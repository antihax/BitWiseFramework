---
title: BitWiseManager

---

# BitWiseManager



 [More...](#detailed-description)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| void | **[BitWiseManager](Classes/class_bit_wise_manager.md#function-bitwisemanager)**() |
| void | **[~BitWiseManager](Classes/class_bit_wise_manager.md#function-~bitwisemanager)**() |
| int | **[GetIndexForKeyword](Classes/class_bit_wise_manager.md#function-getindexforkeyword)**(string mod, string keyword) |
| int | **[ConnectEndpoint](Classes/class_bit_wise_manager.md#function-connectendpoint)**(string mod, string keyword, ScriptCaller caller)<br>Connects an endpoint to a script caller. The endpoint is invoked when the RPC is called.  |
| public string | **[EndPointName](Classes/class_bit_wise_manager.md#function-endpointname)**(string mod, string keyword) |
| void | **[_OnRPC](Classes/class_bit_wise_manager.md#function--onrpc)**(PlayerIdentity sender, Object target, ParamsReadContext ctx) |
| public void | **[_RPC_RPCTable](Classes/class_bit_wise_manager.md#function--rpc-rpctable)**(ParamsReadContext ctx) |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| protected ref map< int, ref ScriptCaller > | **[m_Endpoints](Classes/class_bit_wise_manager.md#variable-m-endpoints)**  |
| protected ref map< string, ref ScriptCaller > | **[m_PendingEndpoints](Classes/class_bit_wise_manager.md#variable-m-pendingendpoints)**  |
| protected ref map< string, int > | **[m_EndpointNames](Classes/class_bit_wise_manager.md#variable-m-endpointnames)**  |
| protected bool | **[m_DirtyRPCTable](Classes/class_bit_wise_manager.md#variable-m-dirtyrpctable)**  |
| protected ref [BitWiseScriptRPC](Classes/class_bit_wise_script_r_p_c.md) | **[m_RPCTableRPC](Classes/class_bit_wise_manager.md#variable-m-rpctablerpc)**  |
| protected int | **[m_EndpointIndex](Classes/class_bit_wise_manager.md#variable-m-endpointindex)**  |

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


### function ~BitWiseManager

```cpp
void ~BitWiseManager()
```


### function GetIndexForKeyword

```cpp
int GetIndexForKeyword(
    string mod,
    string keyword
)
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


## Public Attributes Documentation

### variable m_Endpoints

```cpp
protected ref map< int, ref ScriptCaller > m_Endpoints;
```


### variable m_PendingEndpoints

```cpp
protected ref map< string, ref ScriptCaller > m_PendingEndpoints;
```


### variable m_EndpointNames

```cpp
protected ref map< string, int > m_EndpointNames;
```


### variable m_DirtyRPCTable

```cpp
protected bool m_DirtyRPCTable = true;
```


### variable m_RPCTableRPC

```cpp
protected ref BitWiseScriptRPC m_RPCTableRPC;
```


### variable m_EndpointIndex

```cpp
protected int m_EndpointIndex;
```


-------------------------------

Updated on 2023-08-25 at 22:11:27 -0500