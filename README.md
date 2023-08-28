# BitWise Framework

## Documentation

- [Class documentation](docs/index_classes.md)
- [Examples](docs/index_examples.md)

## About

BitWise is a DayZ RPC Framework to solve some common problems and to not repeat myself in other mods:

1. Mod RPC send far more data than needed.
2. rpc_type are impossible to manage between many other modders.
3. DayZ has solutions but inconsistently used. See `VirtualHud` and `BitArray` in the DayZ Script code.
4. On_RPC ScriptInvoker is not performant.

## Goals

- Compatibility with CF and DayZ existing methods. This is not a replacement for either, can be mixed and matched with CF.
- Pack data on a bit level. A boolean is sent as one bit, a value never to exceed 12 is sent as 5 bits, etc.
- Performant code and minimal bandwidth.
- String coding, including UTF support.
- RPC registration assigning new `rpc_type` as needed to callback a function on receive. Synchronized between client and server.

## License

This work is licensed under the Creative Commons Attribution-NoDerivatives 4.0 International [(CC BY-ND 4.0)](https://creativecommons.org/licenses/by-nd/4.0/)

Author grants permission to Bohemia Interactive for any reason to copy or rehash this code as part of the engine (please do, save my sanity).
