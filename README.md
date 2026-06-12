# Obfuscation Header

UC Thread: https://www.unknowncheats.me/forum/c-and-c-/754651-obfuscation-header.html

## 📋 Macro List

### Assembly Obfuscation

* `ASM_OBFUSCATE_1` — Inline assembly GS register obfuscation.
* `ASM_OBFUSCATE_2` — Inline assembly RDTSC/RBX register check.
* `ASM_FAKE_CALL` — Inline assembly fake call dispatcher.

### Stub Collection

* `STUB_1` → `STUB_20` — 20 variants of complex heavyweight byte-junk stubs.

### Flow Obfuscation

* `JUNK_HEAVY` — Massive timing loop and context obfuscation.
* `BRKIDA` — State machine with nested opaque predicates.
* `BRKIDA_EXTREME` — Multi-layer pre-processed opaque predicate tree.

### Polymorphic Engines

* `POLYMORPHIC_DISPATCH` — 32-state polymorphic dispatcher using RDTSC/GS entropy.
* `POLYMORPHIC_HEAVY` — Multi-layer graph traversal with 48-case state machine.

### Main Engine

* `MEGA_888888888888X(...)` — The main polymorphic VM/obfuscation entry engine.

---

#  Before IDA Graph

![IDA Graph](https://i.imgur.com/BR5RscL.png)

---

#  After IDA Graph

![IDA Graph](https://i.imgur.com/S2jcRxN.png)

---

#  Simple Usage Example

```cpp
#include <iostream>
#include "obf.h"

int main()
{
    MEGA_888888888888X();

    std::cout << "Hello world\n";
}
```
