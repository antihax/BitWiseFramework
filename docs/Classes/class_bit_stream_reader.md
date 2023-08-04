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
| bool | **[ReadBool](Classes/class_bit_stream_reader.md#function-readbool)**() |
| int | **[ReadUint](Classes/class_bit_stream_reader.md#function-readuint)**(int bits) |
| int | **[ReadSInt](Classes/class_bit_stream_reader.md#function-readsint)**(int bits) |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| public int | **[m_BitIndex](Classes/class_bit_stream_reader.md#variable-m-bitindex)**  |
| public Serializer | **[ctx](Classes/class_bit_stream_reader.md#variable-ctx)**  |
| public int | **[m_Working](Classes/class_bit_stream_reader.md#variable-m-working)**  |
| public int | **[m_WorkingIndex](Classes/class_bit_stream_reader.md#variable-m-workingindex)**  |

## Detailed Description

```cpp
class BitStreamReader;
```


[BitStreamReader](Classes/class_bit_stream_reader.md) allows you to read bits to an array of integers from network transmission. 

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
bool ReadBool()
```


### function ReadUint

```cpp
int ReadUint(
    int bits
)
```


### function ReadSInt

```cpp
int ReadSInt(
    int bits
)
```


## Public Attributes Documentation

### variable m_BitIndex

```cpp
public int m_BitIndex = 0;
```


### variable ctx

```cpp
public Serializer ctx;
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

Updated on 2023-08-04 at 16:20:12 -0500