<?php

$SRC_ROOT = __DIR__ . "/native/codegen";
include "$SRC_ROOT/mkcstable.php";

$wconv_t = "#include \"pch.h\"\n";
$wconv_t .= get_function_group("$SRC_ROOT/s2trad/phrase_s2t.txt", "pt_");
$wconv_t .= get_function_group("$SRC_ROOT/s2trad/word_s2t.txt", "wt_");
file_put_contents( __DIR__ . "/../CConv.cpp", $wconv_t );
