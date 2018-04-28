## Translator
### Usage
```csharp
Translator TS_1Phase = new Translator( bytes[] Phase1 );
Translator TS_2Phase = new Translator( byte[] Phase1, byte[] Phase2 )

string Result = TS.Translate( "Text" );
byte[] BytesResult = TS.Translate( new byte[]{ 'a' } );
```

### Table format
The first `,` will be our delimiter. LHS and RHS should have same length. Otherwise it might cause some unwanted effects.
```
1234,5678
3456,298,
```
