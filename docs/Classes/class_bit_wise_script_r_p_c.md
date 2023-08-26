---
title: BitWiseScriptRPC

---

# BitWiseScriptRPC





Inherits from [BitStreamWriter](Classes/class_bit_stream_writer.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| public void | **[BitWiseScriptRPC](Classes/class_bit_wise_script_r_p_c.md#function-bitwisescriptrpc)**(Serializer serializer =NULL) |
| public void | **[SetIndex](Classes/class_bit_wise_script_r_p_c.md#function-setindex)**(int index) |
| void | **[~BitWiseScriptRPC](Classes/class_bit_wise_script_r_p_c.md#function-~bitwisescriptrpc)**() |
| override void | **[Reset](Classes/class_bit_wise_script_r_p_c.md#function-reset)**() |
| void | **[Send](Classes/class_bit_wise_script_r_p_c.md#function-send)**(Object target, bool guaranteed, PlayerIdentity recipient =NULL)<br>Send the RPC on the wire, can be saved and repeated if needed.  |
| [BitWiseScriptRPC](Classes/class_bit_wise_script_r_p_c.md) | **[NewFromID](Classes/class_bit_wise_script_r_p_c.md#function-newfromid)**(int index) |
| [BitWiseScriptRPC](Classes/class_bit_wise_script_r_p_c.md) | **[New](Classes/class_bit_wise_script_r_p_c.md#function-new)**(string mod, string keyword) |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| public ref ScriptRPC | **[m_ScriptRPC](Classes/class_bit_wise_script_r_p_c.md#variable-m-scriptrpc)**  |
| public int | **[m_Index](Classes/class_bit_wise_script_r_p_c.md#variable-m-index)**  |

## Additional inherited members

**Public Functions inherited from [BitStreamWriter](Classes/class_bit_stream_writer.md)**

|                | Name           |
| -------------- | -------------- |
| void | **[BitStreamWriter](Classes/class_bit_stream_writer.md#function-bitstreamwriter)**(Serializer context =NULL)<br>Initializes a [BitStreamWriter](Classes/class_bit_stream_writer.md) object.  |
| void | **[~BitStreamWriter](Classes/class_bit_stream_writer.md#function-~bitstreamwriter)**() |
| int | **[GetIndex](Classes/class_bit_stream_writer.md#function-getindex)**() |
| bool | **[Align](Classes/class_bit_stream_writer.md#function-align)**()<br>Aligns the bitstream to the next integer boundary.  |
| bool | **[WriteUInt](Classes/class_bit_stream_writer.md#function-writeuint)**(int value, int bits) |
| bool | **[WriteSInt](Classes/class_bit_stream_writer.md#function-writesint)**(int value, int bits) |
| bool | **[WriteHalfVector](Classes/class_bit_stream_writer.md#function-writehalfvector)**(vector value) |
| bool | **[WriteHalfFloat](Classes/class_bit_stream_writer.md#function-writehalffloat)**(float value) |
| bool | **[WritePacked](Classes/class_bit_stream_writer.md#function-writepacked)**(bool value) |
| bool | **[WritePacked](Classes/class_bit_stream_writer.md#function-writepacked)**(float value) |
| bool | **[WritePacked](Classes/class_bit_stream_writer.md#function-writepacked)**(vector value) |
| bool | **[WritePacked](Classes/class_bit_stream_writer.md#function-writepacked)**(string value) |
| bool | **[WritePacked](Classes/class_bit_stream_writer.md#function-writepacked)**(Object object) |
| bool | **[WriteAligned](Classes/class_bit_stream_writer.md#function-writealigned)**(int value) |
| bool | **[WriteAligned](Classes/class_bit_stream_writer.md#function-writealigned)**(bool value) |
| bool | **[WriteAligned](Classes/class_bit_stream_writer.md#function-writealigned)**(string value) |

**Public Attributes inherited from [BitStreamWriter](Classes/class_bit_stream_writer.md)**

|                | Name           |
| -------------- | -------------- |
| public int | **[m_BitIndex](Classes/class_bit_stream_writer.md#variable-m-bitindex)**  |
| protected Serializer | **[m_Context](Classes/class_bit_stream_writer.md#variable-m-context)**  |
| public int | **[m_Working](Classes/class_bit_stream_writer.md#variable-m-working)**  |
| public int | **[m_WorkingIndex](Classes/class_bit_stream_writer.md#variable-m-workingindex)**  |


## Public Functions Documentation

### function BitWiseScriptRPC

```cpp
public void BitWiseScriptRPC(
    Serializer serializer =NULL
)
```


### function SetIndex

```cpp
public void SetIndex(
    int index
)
```


### function ~BitWiseScriptRPC

```cpp
void ~BitWiseScriptRPC()
```


### function Reset

```cpp
override void Reset()
```


### function Send

```cpp
void Send(
    Object target,
    bool guaranteed,
    PlayerIdentity recipient =NULL
)
```

Send the RPC on the wire, can be saved and repeated if needed. 

**Parameters**: 

  * **target** The target object of the RPC 
  * **guaranteed** boolean to resend the RPC if it is lost in transit 
  * **recipient** The player to send the RPC to, NULL for all players 


### function NewFromID

```cpp
static BitWiseScriptRPC NewFromID(
    int index
)
```


### function New

```cpp
static BitWiseScriptRPC New(
    string mod,
    string keyword
)
```


## Public Attributes Documentation

### variable m_ScriptRPC

```cpp
public ref ScriptRPC m_ScriptRPC;
```


### variable m_Index

```cpp
public int m_Index;
```


-------------------------------

Updated on 2023-08-25 at 22:01:36 -0500