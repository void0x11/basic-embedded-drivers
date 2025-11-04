# Embedded Drivers Library

A simple, modular collection of drivers for STM32 microcontrollers written in C.  
Each driver handles one specific task (GPIO, timers, communication, etc.) and works independently.

---

## 📌 What Is This?

This library provides **ready-to-use code modules** that let you control microcontroller features without writing low-level register code yourself.

Instead of:
```c
// Complex register manipulation
GPIOA->MODER |= (1U << 0);
GPIOA->OTYPER &= ~(1U << 0);
```

You use:
```c
// Simple, clear function
yourlib_gpio_init(GPIO_A, PIN_0, GPIO_OUTPUT);
yourlib_gpio_write(GPIO_A, PIN_0, 1);
```

Each driver is **independent** — you only include what you need in your project.

---

## 🎯 Quick Start

### 1. Understanding the Structure

Every driver follows the same pattern:

```
gpio/
├─ include/yourlib/gpio.h          ← What you #include
├─ include/yourlib/gpio_config.h   ← Settings you can change
├─ src/gpio.c                      ← How it works (don't touch)
└─ src/private/gpio_private.h      ← Internal details
```

### 2. Using a Driver

```c
#include "yourlib/gpio.h"

int main(void) {
    // Initialize GPIO pin A0 as output
    yourlib_gpio_init(GPIO_A, PIN_0, GPIO_OUTPUT);
    
    // Turn on LED
    yourlib_gpio_write(GPIO_A, PIN_0, 1);
    
    // Turn off LED
    yourlib_gpio_write(GPIO_A, PIN_0, 0);
    
    return 0;
}
```

That's it! The library handles all the details.

---

## 🔧 Available Drivers

| Driver | What It Does | Example Use |
|--------|------------|-------------|
| **gpio** | Read and write digital pins | LED control, button input |
| **rcc** | Enable clocks and system speed | Turn on peripherals |
| **exti** | Respond to pin changes instantly | Button press detection |
| **nvic** | Manage interrupt priorities | Handle hardware interrupts |
| **systick** | Generate time delays | Sleep and timing |
| **usart** | Serial communication (USB, debug) | Print debug messages |
| **dac** | Create analog voltages | Audio, waveform output |
| **ir_sensor** | Send/receive infrared signals | Remote controls |
| **lcd_display** | Character LCD screen | Display text on 16×2 screen |
| **led_matrix** | Control LED grids directly | Dot-matrix displays |
| **led_matrix_shift** | Control LEDs via shift registers | Chain multiple displays |
| **seven_segment** | 7-segment number displays | Digital counters |
| **shift_register** | Serial-to-parallel conversion | Control many pins with few wires |
| **scheduler** | Simple task management | Run multiple timers at once |
| **core_lib** | Shared libraries between some drivers | Common utility & Math functions |

---

## 🚀 Getting Started in 5 Minutes

### Step 1: Add the Library to Your Project

**Option A: Git Submodule (Recommended)**
```bash
git submodule add https://github.com/void0x11/Embedded-Drivers external/embedded-drivers
```

**Option B: Copy Drivers Manually**
Copy the driver folders you need into your project.

### Step 2: Include the Header

```c
#include "yourlib/gpio.h"
#include "yourlib/systick.h"
```

### Step 3: Write Your Code

```c
#include "yourlib/gpio.h"
#include "yourlib/systick.h"

int main(void) {
    // Set up pin A0 as an output
    yourlib_gpio_init(GPIO_A, PIN_0, GPIO_OUTPUT);
    
    while (1) {
        // Turn LED on
        yourlib_gpio_write(GPIO_A, PIN_0, 1);
        yourlib_systick_delay_ms(500);  // Wait 500 ms
        
        // Turn LED off
        yourlib_gpio_write(GPIO_A, PIN_0, 0);
        yourlib_systick_delay_ms(500);
    }
    
    return 0;
}
```

That's a complete blinking LED program!

---

## Real Examples

Ready-to-run example projects are included:

| Example | What It Shows | Best For |
|---------|---------------|----------|
| **blinky/** | LED blinking | First-time setup test |
| **uart_echo/** | Serial communication | Debug output, testing |
| **scheduler_demo/** | Running multiple tasks | Learning timing concepts |
| **matrix_display/** | Animated LED patterns | Display control |

Try the **blinky** example first — it's the simplest way to verify everything works!

---

## ⚙️ Customizing Drivers

Most drivers have a `_config.h` file where you can adjust settings **without changing the driver code**.

### Example: GPIO Configuration

**gpio_config.h:**
```c
#define GPIO_DEFAULT_MODE      GPIO_OUTPUT
#define GPIO_DEBOUNCE_MS       20
```

This keeps your configuration in one place and makes driver updates easy.

---

## 🏗️ Project Organization

```
my_project/
├─ external/
│  └─ embedded-drivers/        ← Library code
├─ src/
│  └─ main.c                   ← Your code
├─ inc/
│  └─ config.h                 ← Your settings
└─ CMakeLists.txt              ← Build instructions
```

---

## 📖 Naming Conventions (Easy Reference)

To keep things consistent and readable:

| Type | Format | Example |
|------|--------|---------|
| Functions | `yourlib_module_action()` | `yourlib_gpio_init()` |
| Constants | `YOURLIB_UPPERCASE_NAME` | `YOURLIB_GPIO_OUTPUT` |
| Config files | `module_config.h` | `gpio_config.h` |

This naming makes it easy to spot library code in your project.

---

## ❓ Common Questions

**Q: Do I need all the drivers?**  
A: No! Include only what you need. The library is modular by design.

**Q: Can I use this for non-STM32 microcontrollers?**  
A: Yes! The drivers are designed to be portable. Add a new folder under `port/` for your target.

**Q: How do I add my own driver?**  
A: Create a new folder following the same structure and naming conventions. Check the contributing guidelines below.

**Q: What if I find a bug?**  
A: Open an issue on GitHub with a simple example that reproduces the problem.

---

## 🤝 Contributing

Found a bug? Want to add a driver? Pull requests are welcome!

**Before submitting:**
- Keep each driver **self-contained** (one file per task)
- Document public functions in the header
- Include a simple example showing how to use your changes
- Follow the coding style (see `.editorconfig`)

---

## 📌 Design Principles

1. **Simple**: Clear function names, minimal parameters
2. **Independent**: Each driver works on its own
3. **Static**: No dynamic memory allocation
4. **Portable**: Easy to move to other microcontrollers
5. **Consistent**: Same style across all drivers

---

## 🛠️ What's Next?

**For Beginners:**
1. Try the **blinky example**
2. Read through a driver header file
3. Modify an example to add your own feature

**For Advanced Users:**
1. Write a custom driver following the template
2. Contribute to the project
3. Adapt drivers for new microcontroller families

---

## 🧩 Future Additions

- **SPI and I2C drivers** — communicate with sensors
- **Enhanced scheduler** — advanced timing modes
- **Unit tests** — verify code works correctly
- **More examples** — practical real-world projects

---

## 📜 License

MIT License © 2025  
Free to use for personal, educational, and commercial projects. Just include the license file.

---

**Happy embedded coding!**