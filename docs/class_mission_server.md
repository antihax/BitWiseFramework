---
title: MissionServer

---

# MissionServer





## Public Functions

|                | Name           |
| -------------- | -------------- |
| override void | **[OnClientPrepareEvent](class_mission_server.md#function-onclientprepareevent)**(PlayerIdentity identity, out bool useDB, out vector pos, out float yaw, out int preloadTimeout)<br>Overrides the OnClientPrepareEvent method to send the RPCTable to the player's identity.  |

## Public Functions Documentation

### function OnClientPrepareEvent

```cpp
override void OnClientPrepareEvent(
    PlayerIdentity identity,
    out bool useDB,
    out vector pos,
    out float yaw,
    out int preloadTimeout
)
```

Overrides the OnClientPrepareEvent method to send the RPCTable to the player's identity. 

-------------------------------

Updated on 2024-01-28 at 13:45:05 -0600