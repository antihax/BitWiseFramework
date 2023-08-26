---
title: BitWiseManager

---

# BitWiseManager



 [More...](#detailed-description)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| void | **[BitWiseManager](class_bit_wise_manager.md#function-bitwisemanager)**() |
| int | **[ConnectEndpoint](class_bit_wise_manager.md#function-connectendpoint)**(string mod, string keyword, ScriptCaller caller)<br>Connects an endpoint to a script caller. The endpoint is invoked when the RPC is called.  |
| public string | **[EndPointName](class_bit_wise_manager.md#function-endpointname)**(string mod, string keyword) |
| int | **[GetIndexForKeyword](class_bit_wise_manager.md#function-getindexforkeyword)**(string mod, string keyword) |
| void | **[_OnRPC](class_bit_wise_manager.md#function--onrpc)**(PlayerIdentity sender, Object target, ParamsReadContext ctx) |
| public void | **[_RPC_RPCTable](class_bit_wise_manager.md#function--rpc-rpctable)**(ParamsReadContext ctx) |
| void | **[~BitWiseManager](class_bit_wise_manager.md#function-~bitwisemanager)**() |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| protected bool | **[m_DirtyRPCTable](class_bit_wise_manager.md#variable-m-dirtyrpctable)**  |
| protected int | **[m_EndpointIndex](class_bit_wise_manager.md#variable-m-endpointindex)**  |
| protected ref map< string, int > | **[m_EndpointNames](class_bit_wise_manager.md#variable-m-endpointnames)**  |
| protected ref map< int, ref ScriptCaller > | **[m_Endpoints](class_bit_wise_manager.md#variable-m-endpoints)**  |
| protected ref map< string, ref ScriptCaller > | **[m_PendingEndpoints](class_bit_wise_manager.md#variable-m-pendingendpoints)**  |
| protected ref [BitWiseScriptRPC](class_bit_wise_script_r_p_c.md) | **[m_RPCTableRPC](class_bit_wise_manager.md#variable-m-rpctablerpc)**  |

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


### function _OnRPC

```cpp
void _OnRPC(
    PlayerIdentity sender,
    Object target,
    ParamsReadContext ctx
)
```


### function _RPC_RPCTable

```cpp
public void _RPC_RPCTable(
    ParamsReadContext ctx
)
```


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
protected ref map< string, int > m_EndpointNames;
```


### variable m_Endpoints

```cpp
protected ref map< int, ref ScriptCaller > m_Endpoints;
```


### variable m_PendingEndpoints

```cpp
protected ref map< string, ref ScriptCaller > m_PendingEndpoints;
```


### variable m_RPCTableRPC

```cpp
protected ref BitWiseScriptRPC m_RPCTableRPC;
```


-------------------------------

Updated on 2023-08-26 at 11:48:46 -0500