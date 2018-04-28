## Translator
Translator is a multi-phase binary translation library that uses aho-corasick matching algorithm.

### Usage
```csharp
using libtranslate;

Translator Conv = new Translator();
Conv.AddTable( byte[] Table1 ); // Add Phase 1 translation table
Conv.AddTable( byte[] Table2 ); // Add Phase 2 translation table
Conv.AddTable( byte[] Table3 ); // ...
Conv.AddTable( byte[] Table4 );

string Result = Conv.Translate( "Text" );
byte[] BytesResult = Conv.Translate( new byte[]{ 'a' } );
```

### Table format
The first `,` will be our delimiter. LHS and RHS should have same length. Otherwise it might cause some unwanted effects.
```
1234,5678
3456,298,
```

1st line: `LHS = 1234 | RHS = 5678`

2nd line: `LHS = 3456 | RHS = 298,`
