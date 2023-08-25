---
title: BitStreamReader

---

# BitStreamReader



 [More...](#detailed-description)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| void | **[BitStreamReader](Classes/class_bit_stream_reader.md#function-bitstreamreader)**(Serializer _ctx) |
| void | **[~BitStreamReader](Classes/class_bit_stream_reader.md#function-~bitstreamreader)**() |
| int | **[GetIndex](Classes/class_bit_stream_reader.md#function-getindex)**() |
| bool | **[ReadBool](Classes/class_bit_stream_reader.md#function-readbool)**(out bool value) |
| bool | **[ReadUInt](Classes/class_bit_stream_reader.md#function-readuint)**(out int value, int bits) |
| bool | **[ReadSInt](Classes/class_bit_stream_reader.md#function-readsint)**(out int value, int bits) |
| void | **[Align](Classes/class_bit_stream_reader.md#function-align)**()<br>Aligns the bitstream to the next integer boundary.  |
| bool | **[ReadPacked](Classes/class_bit_stream_reader.md#function-readpacked)**(out bool value) |
| bool | **[ReadPacked](Classes/class_bit_stream_reader.md#function-readpacked)**(out int value) |
| bool | **[ReadPacked](Classes/class_bit_stream_reader.md#function-readpacked)**(out float value) |
| bool | **[ReadPacked](Classes/class_bit_stream_reader.md#function-readpacked)**(out string value) |
| bool | **[ReadAligned](Classes/class_bit_stream_reader.md#function-readaligned)**(out int value) |
| bool | **[ReadAligned](Classes/class_bit_stream_reader.md#function-readaligned)**(out bool value) |
| bool | **[ReadAligned](Classes/class_bit_stream_reader.md#function-readaligned)**(out Class value) |
| bool | **[ReadAligned](Classes/class_bit_stream_reader.md#function-readaligned)**(out string value) |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| public int | **[m_BitIndex](Classes/class_bit_stream_reader.md#variable-m-bitindex)**  |
| public Serializer | **[m_Context](Classes/class_bit_stream_reader.md#variable-m-context)**  |
| public int | **[m_Working](Classes/class_bit_stream_reader.md#variable-m-working)**  |
| public int | **[m_WorkingIndex](Classes/class_bit_stream_reader.md#variable-m-workingindex)**  |

## Detailed Description

```cpp
class BitStreamReader;
```


This class is responsible for reading data into a bitstream. It provides methods to read various types of data (like integers, floats, etc.) from the bitstream. 

## Public Functions Documentation

### function BitStreamReader

```cpp
void BitStreamReader(
    Serializer _ctx
)
```


### function ~BitStreamReader

```cpp
void ~BitStreamReader()
```


### function GetIndex

```cpp
int GetIndex()
```


### function ReadBool

```cpp
bool ReadBool(
    out bool value
)
```


### function ReadUInt

```cpp
bool ReadUInt(
    out int value,
    int bits
)
```


### function ReadSInt

```cpp
bool ReadSInt(
    out int value,
    int bits
)
```


### function Align

```cpp
void Align()
```

Aligns the bitstream to the next integer boundary. 

Generally, this function is only called at the end of a message to ensure proper alignment. 


### function ReadPacked

```cpp
bool ReadPacked(
    out bool value
)
```


### function ReadPacked

```cpp
bool ReadPacked(
    out int value
)
```


### function ReadPacked

```cpp
bool ReadPacked(
    out float value
)
```


### function ReadPacked

```cpp
bool ReadPacked(
    out string value
)
```


### function ReadAligned

```cpp
bool ReadAligned(
    out int value
)
```


### function ReadAligned

```cpp
bool ReadAligned(
    out bool value
)
```


### function ReadAligned

```cpp
bool ReadAligned(
    out Class value
)
```


### function ReadAligned

```cpp
bool ReadAligned(
    out string value
)
```


## Public Attributes Documentation

### variable m_BitIndex

```cpp
public int m_BitIndex = 0;
```


### variable m_Context

```cpp
public Serializer m_Context;
```


### variable m_Working

```cpp
public int m_Working;
```


### variable m_WorkingIndex

```cpp
public int m_WorkingIndex;
```


-------------------------------

Updated on 2023-08-25 at 15:23:18 -0500