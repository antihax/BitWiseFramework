---
title: BitWiseScriptRPC

---

# BitWiseScriptRPC





Inherits from [BitStreamWriter](class_bit_stream_writer.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| public void | **[BitWiseScriptRPC](class_bit_wise_script_r_p_c.md#function-bitwisescriptrpc)**(Serializer serializer =NULL) |
| [BitWiseScriptRPC](class_bit_wise_script_r_p_c.md) | **[New](class_bit_wise_script_r_p_c.md#function-new)**(string mod, string keyword) |
| [BitWiseScriptRPC](class_bit_wise_script_r_p_c.md) | **[NewFromID](class_bit_wise_script_r_p_c.md#function-newfromid)**(int index) |
| override void | **[Reset](class_bit_wise_script_r_p_c.md#function-reset)**() |
| void | **[Send](class_bit_wise_script_r_p_c.md#function-send)**(Object target, bool guaranteed, PlayerIdentity recipient =NULL)<br>Send the RPC on the wire, can be saved and repeated if needed.  |
| public void | **[SetIndex](class_bit_wise_script_r_p_c.md#function-setindex)**(int index) |
| void | **[~BitWiseScriptRPC](class_bit_wise_script_r_p_c.md#function-~bitwisescriptrpc)**() |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| public int | **[m_Index](class_bit_wise_script_r_p_c.md#variable-m-index)**  |
| public ref ScriptRPC | **[m_ScriptRPC](class_bit_wise_script_r_p_c.md#variable-m-scriptrpc)**  |

## Additional inherited members

**Public Functions inherited from [BitStreamWriter](class_bit_stream_writer.md)**

|                | Name           |
| -------------- | -------------- |
| bool | **[Align](class_bit_stream_writer.md#function-align)**()<br>Aligns the bitstream to the next integer boundary.  |
| void | **[BitStreamWriter](class_bit_stream_writer.md#function-bitstreamwriter)**(Serializer context =NULL)<br>Initializes a [BitStreamWriter](class_bit_stream_writer.md) object.  |
| int | **[GetIndex](class_bit_stream_writer.md#function-getindex)**() |
| bool | **[WriteAligned](class_bit_stream_writer.md#function-writealigned)**(int value) |
| bool | **[WriteAligned](class_bit_stream_writer.md#function-writealigned)**(bool value) |
| bool | **[WriteAligned](class_bit_stream_writer.md#function-writealigned)**(string value) |
| bool | **[WriteHalfFloat](class_bit_stream_writer.md#function-writehalffloat)**(float value) |
| bool | **[WriteHalfVector](class_bit_stream_writer.md#function-writehalfvector)**(vector value) |
| bool | **[WritePacked](class_bit_stream_writer.md#function-writepacked)**(bool value) |
| bool | **[WritePacked](class_bit_stream_writer.md#function-writepacked)**(float value) |
| bool | **[WritePacked](class_bit_stream_writer.md#function-writepacked)**(vector value) |
| bool | **[WritePacked](class_bit_stream_writer.md#function-writepacked)**(string value) |
| bool | **[WritePacked](class_bit_stream_writer.md#function-writepacked)**(Object object) |
| bool | **[WriteSInt](class_bit_stream_writer.md#function-writesint)**(int value, int bits) |
| bool | **[WriteUInt](class_bit_stream_writer.md#function-writeuint)**(int value, int bits) |
| void | **[~BitStreamWriter](class_bit_stream_writer.md#function-~bitstreamwriter)**() |

**Public Attributes inherited from [BitStreamWriter](class_bit_stream_writer.md)**

|                | Name           |
| -------------- | -------------- |
| public int | **[m_BitIndex](class_bit_stream_writer.md#variable-m-bitindex)**  |
| protected Serializer | **[m_Context](class_bit_stream_writer.md#variable-m-context)**  |
| public int | **[m_Working](class_bit_stream_writer.md#variable-m-working)**  |
| public int | **[m_WorkingIndex](class_bit_stream_writer.md#variable-m-workingindex)**  |


## Public Functions Documentation

### function BitWiseScriptRPC

```cpp
public void BitWiseScriptRPC(
    Serializer serializer =NULL
)
```


### function New

```cpp
static BitWiseScriptRPC New(
    string mod,
    string keyword
)
```


### function NewFromID

```cpp
static BitWiseScriptRPC NewFromID(
    int index
)
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


## Public Attributes Documentation

### variable m_Index

```cpp
public int m_Index;
```


### variable m_ScriptRPC

```cpp
public ref ScriptRPC m_ScriptRPC;
```


-------------------------------

Updated on 2023-08-26 at 11:48:46 -0500