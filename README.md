# BitWise Framework

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

## Usage

BitWise Framework allows endpoints to be registered on the server. Registering an endpoint takes a ModName and Keyword and returns an RPC index that is synchronized between server and client for future use.

Endpoints should be registered in `MissionServer::OnInit()`.

```cpp
m_RPC_SENDMESSAGE = GetBitWiseManager().RegisterEndpoint("MyAmazingMod", "SendMessage");
```

Once registered, an endpoint function can be connected on either the server or client.
In this example, we register the receiving endpoint function on a client in `MissionBase::MissionBase()`

```cpp
GetBitWiseManager().ConnectEndpoint("MyAmazingMod", "SendMessage", ScriptCaller.Create(RPC_SendMessage));
```

In our example, we will send the message from the server to the client using a BitWiseScriptRPC object.

```cpp
autoptr BitWiseScriptRPC rpc = BitWiseScriptRPC.NewFromID(m_RPC_SENDMESSAGE);
rpc.WritePacked("Hello World!");
rpc.Send(null, true, sender.GetIdentity());
```

On the client we create the receiving endpoint function.

```cpp
bool RPC_SendMessage(PlayerIdentity sender, Object target, ParamsReadContext ctx) {
    BitStreamReader br = new BitStreamReader(ctx);

    // Read and print the packed message
    string message;
    if (!br.ReadPacked(message))
        return false;
    print(message);

    return true;
}
```

## Best Practices

#### Contexts

It is best to contain the RPC logic as much as possible within context classes to avoid namespace collisions with other mods within base DayZ game classes.

For a more complex example see `SerializeRPC` and `DeserializeRPC` in [settings.c](https://github.com/antihax/RadioNotifications/blob/main/scripts/game/radionotificationsettings.c)

These functions are called by a server manager class in `SendConfiguration` [manager.c](https://github.com/antihax/RadioNotifications/blob/97ecc107a4f1e54b65381a4cafcbf7c24c09e94b/scripts/game/radionotificationmanager.c) and a client handler context to read the data `ConfigurationRPC` in [client.c](https://github.com/antihax/RadioNotifications/blob/97ecc107a4f1e54b65381a4cafcbf7c24c09e94b/scripts/game/radionotificationclienthandler.c)

### Minimize data transfer

DayZ packets are limited to 1456 bytes and the larger a packet is, the longer it takes to send, creating latency for the player.

With this in mind, it is best to optimize the amount of data required to be sent. If the ranges of data are known, state them with the ranged API similar to NetSyncVars. Use constants to define the ranges to help control in one location.

#### Using string tables

A common mistake is sending static strings instead of using an enum and string table on the client.

```cpp
enum Messages {
    PlayerJoined,
    PlayerLeft
}
StringArray messageTable = {
    "Player %1 joined the game",
    "Player %1 left the game" };

rpc.WriteUInt(Messages.PlayerJoined, 0, EnumTools.GetEnumSize(Messages));
```

```cpp
int msg;
rpc.ReadUInt(msg, 0, EnumTools.GetEnumSize(Messages));
PrintFormat(messageTable[msg], player.GetName());
```

The result here is that 3 - 32 bits of data are sent instead of 208 or more when sending the whole string.

#### Avoid aligned writes/reads
Aligned writes and reads are provided to allow the bitstream to be aligned to the next integer so the standard Context can be used, such as to perform a deep serialization of an object.

## Documentation

- [Class documentation](docs/index_classes.md)
- [Examples](docs/index_examples.md)

## License

This work is licensed under the Creative Commons Attribution-NoDerivatives 4.0 International [(CC BY-ND 4.0)](https://creativecommons.org/licenses/by-nd/4.0/)

Author grants permission to Bohemia Interactive for any reason to copy or rehash this code as part of the engine (please do, save my sanity).
