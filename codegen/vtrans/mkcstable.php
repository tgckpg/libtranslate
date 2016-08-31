<?php

$SRC_ROOT = __DIR__ . "/../native/codegen";
include "$SRC_ROOT/mkcstable.php";

$byteX_match_function = function( $token, $seq_num )
{
    return <<< ___BYTEARR___

void match_$token$seq_num(unsigned char const* str, int start, char const* &out, int &step_size)
{
  step_size = __TOKEN_0__;

___BYTEARR___;
};

$org = $generate_match_function;

$generate_match_function = function( $byteX, $seq_num, $token )
{
    global $org;
    if( $seq_num === "ascii" )
    {
        // 0 means no matches
        // ASCII matches always step forward
        return str_replace(
            [ "step_size = 0", "step_size = __TOKEN_0__" ]
            , [ "step_size = 1", "step_size = 0" ]
            , $org( $byteX, $seq_num, $token )
        );
    }

    return str_replace(
        "step_size = __TOKEN_0__"
        , "step_size = 0"
        , $org( $byteX, $seq_num, $token )
    );
};


$wconv_t = "#include \"pch.h\"\n";
$wconv_t .= get_function_group( __DIR__ . "/table.txt", "w_" );
file_put_contents( __DIR__ . "/../../SymConv.cpp", $wconv_t );
