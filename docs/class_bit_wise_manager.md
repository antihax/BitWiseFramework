---
title: BitWiseManager

---

# BitWiseManager



 [More...](#detailed-description)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| void | **[BitWiseManager](class_bit_wise_manager.md#function-bitwisemanager)**()<br>Initializes a [BitWiseManager](class_bit_wise_manager.md) object. Access through `GetBitWiseManager()` |
| int | **[ConnectEndpoint](class_bit_wise_manager.md#function-connectendpoint)**(string mod, string keyword, ScriptCaller caller)<br>Connects an endpoint to a script caller. The endpoint is invoked when the RPC is called.  |
| public string | **[EndPointName](class_bit_wise_manager.md#function-endpointname)**(string mod, string keyword) |
| int | **[GetIndexForKeyword](class_bit_wise_manager.md#function-getindexforkeyword)**(string mod, string keyword)<br>Returns the endpoint index for a given mod and keyword.  |
| int | **[RegisterEndpoint](class_bit_wise_manager.md#function-registerendpoint)**(string mod, string keyword)<br>Registers an endpoint for a mod and keyword for either client or server reception. Must be called on the server as early as possible.  |
| void | **[_OnRPC](class_bit_wise_manager.md#function--onrpc)**(PlayerIdentity sender, Object target, ParamsReadContext ctx)<br>Internal function to handle RPCs.  |
| public void | **[_RPC_RPCTable](class_bit_wise_manager.md#function--rpc-rpctable)**(ParamsReadContext ctx)<br>Internal function decode RPCTable.  |
| void | **[_SendRPCTable](class_bit_wise_manager.md#function--sendrpctable)**(PlayerIdentity identity)<br>Internal function to send RPCTable to a client.  |
| void | **[~BitWiseManager](class_bit_wise_manager.md#function-~bitwisemanager)**() |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| protected bool | **[m_DirtyRPCTable](class_bit_wise_manager.md#variable-m-dirtyrpctable)**  |
| protected int | **[m_EndpointIndex](class_bit_wise_manager.md#variable-m-endpointindex)**  |
| protected autoptr map< string, int > | **[m_EndpointNames](class_bit_wise_manager.md#variable-m-endpointnames)**  |
| protected autoptr map< int, ref ScriptCaller > | **[m_Endpoints](class_bit_wise_manager.md#variable-m-endpoints)**  |
| protected autoptr map< string, ref ScriptCaller > | **[m_PendingEndpoints](class_bit_wise_manager.md#variable-m-pendingendpoints)**  |
| protected autoptr [BitWiseScriptRPC](class_bit_wise_script_r_p_c.md) | **[m_RPCTableRPC](class_bit_wise_manager.md#variable-m-rpctablerpc)**  |

## Detailed Description

```cpp
class BitWiseManager;
```


RPC registration and invokation for BitWise RPCs. This class is not accessible to developers and should be accessed through GetBitWiseManager(). 

## Public Functions Documentation

### function BitWiseManager

```cpp
void BitWiseManager()
```

Initializes a [BitWiseManager](class_bit_wise_manager.md) object. Access through `GetBitWiseManager()`

### function ConnectEndpoint

```cpp
int ConnectEndpoint(
    string mod,
    string keyword,
    ScriptCaller caller
)
```

Connects an endpoint to a script caller. The endpoint is invoked when the RPC is called. 

**Parameters**: 

  * **mod** The mod name. 
  * **keyword** The keyword. 
  * **caller** The script caller to run on RPC. 


**Return**: The endpoint index. 

### function EndPointName

```cpp
public string EndPointName(
    string mod,
    string keyword
)
```


### function GetIndexForKeyword

```cpp
int GetIndexForKeyword(
    string mod,
    string keyword
)
```

Returns the endpoint index for a given mod and keyword. 

**Parameters**: 

  * **mod** The mod name. 
  * **keyword** The keyword. 


**Return**: The endpoint index. 

### function RegisterEndpoint

```cpp
int RegisterEndpoint(
    string mod,
    string keyword
)
```

Registers an endpoint for a mod and keyword for either client or server reception. Must be called on the server as early as possible. 

**Parameters**: 

  * **mod** The mod name. 
  * **keyword** The keyword. 


**Return**: The endpoint index. 

**Note**: This function is only available on the server. 

### function _OnRPC

```cpp
void _OnRPC(
    PlayerIdentity sender,
    Object target,
    ParamsReadContext ctx
)
```

Internal function to handle RPCs. 

### function _RPC_RPCTable

```cpp
public void _RPC_RPCTable(
    ParamsReadContext ctx
)
```

Internal function decode RPCTable. 

### function _SendRPCTable

```cpp
void _SendRPCTable(
    PlayerIdentity identity
)
```

Internal function to send RPCTable to a client. 

### function ~BitWiseManager

```cpp
void ~BitWiseManager()
```


## Public Attributes Documentation

### variable m_DirtyRPCTable

```cpp
protected bool m_DirtyRPCTable = true;
```


### variable m_EndpointIndex

```cpp
protected int m_EndpointIndex;
```


### variable m_EndpointNames

```cpp
protected autoptr map< string, int > m_EndpointNames;
```


### variable m_Endpoints

```cpp
protected autoptr map< int, ref ScriptCaller > m_Endpoints;
```


### variable m_PendingEndpoints

```cpp
protected autoptr map< string, ref ScriptCaller > m_PendingEndpoints;
```


### variable m_RPCTableRPC

```cpp
protected autoptr BitWiseScriptRPC m_RPCTableRPC;
```


-------------------------------

Updated on 2024-01-27 at 14:16:25 -0600