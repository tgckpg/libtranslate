#### Prerequisities
- PHP: For generating codes

#### How to build
1. Run these commands.
```Bash
cd codegen/native
git submodule init
git submodule update
cd ../../
php codegen/s2trad.php
php codegen/synpatch/mkcstable.php
php codegen/vtrans/mkcstable.php
```
3. Build it
