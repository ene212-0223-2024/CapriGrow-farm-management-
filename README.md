# CapriGrow Farm Management System

A C++ command-line system for managing my greenhouse farm — tracks daily watering, the weekly spray programme, and harvest sales. Built for EEC 2212 — Object Oriented Programming.

Kennedy Kimani — ENE212-0223/2024

## What it does

Three modules behind a simple login + menu:

- Watering Log — daily watering times for each greenhouse (Passarella, Illanga, Mydas RZ)

- Spray Schedule — the weekly chemical programme

- Harvest Tracker — records crop sales (crop, kg, price, buyer)

## OOP concepts covered

| Concept | Where to look |
|---|---|
| Abstraction | FarmModule — pure virtual execute() |
| Inheritance | IrrigationModule, SprayModule, HarvestModule extend FarmModule |
| Polymorphism | vector<FarmModule*> with dynamic dispatch in runMenu() |
| Encapsulation | loggedIn private in CapriGrowSystem, name protected in FarmModule |
| Function overloading | Three log() versions in HarvestModule |
| Virtual destructor | ~FarmModule() declared virtual |

## Build and run
