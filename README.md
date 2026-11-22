# Solar-Compatibility-Checker
A C program that checks if a solar-powered device is compatible with your solar panel setup.

*Built during 1st Year, 1st Semester (BSIS - Cebu Technological University, Main Campus)*

## What it does
- Lets you pick a solar product: LED bulb, Fan, Refrigerator, or Water pump
- Asks for your setup details: device voltage, panel wattage, battery voltage, and inverter amps
- Checks if your setup is enough for the product you picked
- Gives tips if your setup needs an upgrade
- Shows a simple voltage x amps = watts table at the end
- You can check more than one product without restarting the program

## How I made it
- Language: C
- Editor: VS Code (with C/C++ extension)

## How to run it
1. Open the file in VS Code
2. Use the Run button from the C/C++ extension
   (or type in terminal: gcc solar.c -o solar then ./solar)
3. You can also run it using an online C compiler website 
   (like OnlineGDB or Programiz) if you don't have VS Code set up

## My Experience
The hard part for me wasn't the syntax — it was the complexity of solar systems in general, 
since that's the topic I chose. I got frustrated every time my calculations were wrong or 
had logical errors. I knew the syntax, but implementing it with accurate and correct solar 
facts was the real challenge. Every day I worked on this project, I improved a little more — 
fixing bugs, researching more about solar, and finding wrong calculations or logical errors. 
Over time, my code got better. Our professor also wanted us to apply selection first, then 
repetition, then arrays and functions, to show that we actually learned each topic.

## Roadmap
This project started as a command-line tool in C and is now expanding into an interactive web application so anyone can check solar setup compatibility directly in their browser:
- **CLI Improvements:** Refine input handling (such as supporting lowercase product codes), clean up compatibility checks, and make the `V × A = W` wattage table easier to read.
- **Web App Version:** Build a clean, mobile-friendly web interface (deployable via GitHub Pages) that mirrors the solar compatibility logic and provides clear upgrade recommendations.
- **Expanded Device Profiles:** Add more solar appliances and realistic voltage/wattage thresholds while keeping the calculations transparent and easy to understand.

## Contributing
Contributions, bug fixes, feature ideas, and improvements to either the C CLI code or the upcoming web version are warmly welcome! Whether you are fixing a small logic bug, improving documentation, or helping build the web interface, feel free to open an issue to discuss an idea or fork the repository and submit a pull request. Please check `CONTRIBUTING.md` for step-by-step instructions before getting started.
