# 🕐 Digital Clock (C)

A simple command-line digital clock built in C that displays the live time and date, refreshing every second — with colored terminal output for a clean, readable look.

## Features

- Real-time clock updated every second
- Choice of **12-hour** or **24-hour** time format
- Displays the current date (day, month, date, year)
- Color-coded output using ANSI escape codes
- Auto-clears the screen each refresh for a smooth display
- Cross-platform screen clearing (`cls` on Windows, `clear` on Unix/macOS)

## How It Works

- `fill_time()` uses the `time.h` library to fetch the current system time and formats it based on user choice (`%H:%M:%S` for 24-hour, `%I:%M:%S %p` for 12-hour).
- `fill_date()` formats the current date as `Weekday Month DD YYYY`.
- `input_format()` prompts the user to choose a time format at startup.
- `clear_screen()` clears the terminal before each redraw, using preprocessor checks to support both Windows and Unix-based systems.
- The `main()` function runs an infinite loop, updating and printing the time/date every 1000 milliseconds using `Sleep()`.

## Tech Used

- Language: **C**
- Libraries: `stdio.h`, `stdlib.h`, `time.h`, `windows.h`

## How to Run

> ⚠️ Note: This program uses `windows.h` and `Sleep()`, so it currently runs on **Windows** only. For Linux/macOS, replace `Sleep(1000)` with `usleep(1000000)` from `unistd.h`.

```bash
gcc digital_clock.c -o digital_clock
./digital_clock
```

## Sample Output

```
DIGITAL CLOCK

current time : 09:42:15 PM
date : Wednesday September 09 2026

developed by Taranveer Singh Jassal
```

## Author

**Taranveer Singh Jassal**
