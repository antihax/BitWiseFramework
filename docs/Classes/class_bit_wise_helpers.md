---
title: BitWiseHelpers
summary: A framework for creating RPCs (Remote Procedure Calls) in DayZ in an optimized way to minimize bandwidth usage and resolve collisions. 

---

# BitWiseHelpers



A framework for creating RPCs (Remote Procedure Calls) in DayZ in an optimized way to minimize bandwidth usage and resolve collisions.  [More...](#detailed-description)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| string | **[BitRepresentation](Classes/class_bit_wise_helpers.md#function-bitrepresentation)**(int value)<br>Binary representation of the value, useful for debugging.  |
| void | **[WarningWithStack](Classes/class_bit_wise_helpers.md#function-warningwithstack)**(string message)<br>Helper function to dump the stack to a string with a message.  |

## Detailed Description

```cpp
class BitWiseHelpers;
```

A framework for creating RPCs (Remote Procedure Calls) in DayZ in an optimized way to minimize bandwidth usage and resolve collisions. 

This framework is designed to be used by modders to create RPCs in DayZ.

Helper functions for the RPC framework held within a namespace to avoid collisions with other mods. 

## Public Functions Documentation

### function BitRepresentation

```cpp
string BitRepresentation(
    int value
)
```

Binary representation of the value, useful for debugging. 

**Parameters**: 

  * **value** 


**Return**: string of the value in binary. 

### function WarningWithStack

```cpp
void WarningWithStack(
    string message
)
```

Helper function to dump the stack to a string with a message. 

**Parameters**: 

  * **str** Message before the stack dump. 


-------------------------------

Updated on 2023-08-10 at 22:33:44 -0500