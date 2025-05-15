# **ft_printf** 📝  
**A simplified printf implementation**  

![C](https://img.shields.io/badge/C-00599C?logo=c&logoColor=white)  
![GitHub last commit](https://img.shields.io/github/last-commit/flotschilein/ft_printf)  
---

## **📖 Description**  
**ft_printf** is a lightweight implementation of `printf` that handles basic format specifiers (`%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`) without bonus flags.  

---

## **🛠️ Features**  

### **Supported Format Specifiers**  
| Specifier | Output                          |  
|-----------|---------------------------------|  
| `%c`      | Single character                |  
| `%s`      | Null-terminated string          |  
| `%p`      | Pointer address in hexadecimal  |  
| `%d`/`%i` | Signed decimal integer          |  
| `%u`      | Unsigned decimal integer        |  
| `%x`      | Lowercase hexadecimal           |  
| `%X`      | Uppercase hexadecimal           |  
| `%%`      | Percent sign                    |  

---

## **🚀 Installation**  
```bash
git clone https://github.com/flotschilein/ft_printf.git
cd ft_printf
make
```
**Output:** `libftprintf.a`  

---

## **📜 Basic Usage**  
```c
#include "ft_printf.h"

int main() {
    ft_printf("Char: %c\n", 'A');
    ft_printf("String: %s\n", "Hello");
    ft_printf("Pointer: %p\n", &main);
    ft_printf("Decimal: %d\n", -42);
    ft_printf("Unsigned: %u\n", 255);
    ft_printf("Hex (lower): %x\n", 255);  // prints "ff"
    ft_printf("Hex (upper): %X\n", 255);  // prints "FF"
    return 0;
}
```

---

## **🧠 Core Logic**  
1. **Parsing**  
   - Scans the format string for `%`.  
   - Processes the next character as a specifier.  

2. **Conversion**    
   - Converts numbers to strings via `ft_itoa` (for `%d`/`%i`)  

3. **Output**  
   - Writes converted strings character-by-character using `write(1, ...)`.  

---

## **⚠️ Limitations **  
- No field width (`%10s`), precision (`%.5d`), or flags (`%-`, `0`, `+`, `#`, ` `).  
- No `*` for dynamic width/precision.  

---

Made with ❤️ by **Florian**  
