<?php

$SRC_ROOT = __DIR__ . "/../native/codegen";
include "$SRC_ROOT/mkcstable.php";

$wconv_t = "#include \"pch.h\"\n";
$wconv_t .= get_function_group("table.txt", "w_");
file_put_contents(__DIR__ . "/../../SymConv.cpp", $wconv_t);
