---
title: BitWiseManager

---

# BitWiseManager





## Public Functions

|                | Name           |
| -------------- | -------------- |
| void | **[BitWiseManager](Classes/class_bit_wise_manager.md#function-bitwisemanager)**() |
| void | **[~BitWiseManager](Classes/class_bit_wise_manager.md#function-~bitwisemanager)**() |
| int | **[RegisterEndpoint](Classes/class_bit_wise_manager.md#function-registerendpoint)**(string mod, string keyword, func fn) |
| public string | **[EndPointName](Classes/class_bit_wise_manager.md#function-endpointname)**(string mod, string keyword) |
| void | **[OnRPC](Classes/class_bit_wise_manager.md#function-onrpc)**(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| protected ref map< int, ref ScriptCaller > | **[m_Endpoints](Classes/class_bit_wise_manager.md#variable-m-endpoints)**  |
| protected ref map< string, ref ScriptCaller > | **[m_PendingEndpoints](Classes/class_bit_wise_manager.md#variable-m-pendingendpoints)**  |
| protected ref map< string, int > | **[m_EndpointNames](Classes/class_bit_wise_manager.md#variable-m-endpointnames)**  |
| protected int | **[m_EndpointIndex](Classes/class_bit_wise_manager.md#variable-m-endpointindex)**  |

## Public Functions Documentation

### function BitWiseManager

```cpp
void BitWiseManager()
```


### function ~BitWiseManager

```cpp
void ~BitWiseManager()
```


### function RegisterEndpoint

```cpp
int RegisterEndpoint(
    string mod,
    string keyword,
    func fn
)
```


### function EndPointName

```cpp
public string EndPointName(
    string mod,
    string keyword
)
```


### function OnRPC

```cpp
void OnRPC(
    PlayerIdentity sender,
    Object target,
    int rpc_type,
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


### variable m_EndpointIndex

```cpp
protected int m_EndpointIndex;
```


-------------------------------

Updated on 2023-08-10 at 22:33:44 -0500