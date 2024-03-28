#include "Animal.h"
#include <string.h>

Animal::Animal(): mass(0), sex(NULL), color(""), age(0){
}

Animal::Animal(float a_mass, const char* a_sex, const char* a_color, int a_age)
    : mass(a_mass), sex(nullptr), color(nullptr), age(a_age) {
  sex = new char[strlen(a_sex) + 1];
  strcpy(sex, a_sex);

  color = new char[strlen(a_color) + 1];
  strcpy(color, a_color);
}

Animal::Animal(const Animal& copy) {
  mass = copy.mass;

  sex = new char[strlen(copy.sex) + 1];
  strcpy(sex, copy.sex);

  color = new char[strlen(copy.color) + 1];
  strcpy(color, copy.color);

  age = copy.age;
}

Animal::Animal(Animal&& move){
  mass = move.mass;
  sex = move.sex;
  color = move.color;
  age = move.age;

  move.mass = 0;
  move.sex = NULL;
  move.color = NULL;
  move.age = 0;
}

Animal::~Animal() {
  delete[] sex;
  delete[] color;
}

float Animal::GetMass() {
  return mass;
}

char *Animal::GetSex() {
  return sex;
}

int Animal::GetAge() {
  return age;
}

char *Animal::GetColor() {
  return color;
}

void Animal::SetMass(float newMass) {
  mass = newMass;
}

void Animal::SetSex(const char *newSex) {
  delete[] sex;
  sex = new char[strlen(newSex) + 1];
  strcpy(sex, newSex);
}

void Animal::SetAge(int newAge) {
  age = newAge;
}

void Animal::SetColor(const char *newColor) {
  delete[] color;
  color = new char[strlen(newColor) + 1];
  strcpy(color, newColor);
}

Animal &Animal::operator=(const Animal &other) {
  if (this == &other) {
    return *this;
  } else {
    mass = other.mass;
    age = other.age;
    SetColor(other.color);
    SetSex(other.sex);
    return *this;
  }
}

Animal &Animal::operator=(Animal &&other){
  if (this == &other) {
    return *this;
  } else {
    mass = move(other.mass);
    age = move(other.age);
    color = move(other.color);
    sex = move(other.sex);
    other.mass = 0.0;
    other.age = 0;
    other.color = nullptr;
    other.sex = nullptr;
    return *this;
  }
}

void Dog::WhatDoesSay(){
  std::cout << "Woof! Woof!" << std::endl;
}

Dog::Dog() : name(NULL), race(Breed::Labrador){
}
Dog::Dog(char *d_name, Breed d_race, float d_mass, char* d_sex, char* d_color, int d_age) {
  Animal(d_mass, d_sex, d_color, d_age);

  name = new char[strlen(d_name) + 1];
  strcpy(name, d_name);

  race = d_race;
}

Dog::Dog(const Dog &copy): Animal(copy), race(copy.race) {
  name = new char[strlen(copy.name) + 1];
  strcpy(name, copy.name);
}

Dog::Dog(Dog &&move): Animal(std::move(move)), name(move.name), race(move.race) {
  name = NULL;
}

Dog::~Dog(){
  delete[] name;
}

Dog &Dog::operator=(Dog &copy) {
  if (this != &copy){
    Animal::operator=(copy);
    delete[] name;
    name = new char[strlen(copy.name) + 1];
    strcpy(name, copy.name);
    race = copy.race;
  }
  return *this;
}

Dog &Dog::operator=(Dog &&move) {
  if (this != &move) {
    Animal::operator=(std::move(move));
    delete[] name;
    name = move.name;
    move.name = nullptr;
    race = move.race;
  }
  return *this;
}

char *Dog::GetName() {
  return name;
}

Breed Dog::GetRace() {
  return race;
}

void Dog::SetName(char *newName) {
  name = newName;
}

void Dog::SetRace(Breed newRace) {
  race = newRace;
}

void Fox::WhatDoesSay() {
  switch (type) {
    case TypeFox::ArcticFox:
      std::cout << "Wa-pa-pa-pa-pa-pa-pow!\n"
                   "Wa-pa-pa-pa-pa-pa-pow!\n"
                   "Wa-pa-pa-pa-pa-pa-pow!" << std::endl;
      break;
    case TypeFox::RedFox:
      std::cout << "Hatee-hatee-hatee-ho!\n"
                   "Hatee-hatee-hatee-ho!\n"
                   "Hatee-hatee-hatee-ho!" << std::endl;
      break;
    case TypeFox::FennecFox:
      std::cout << "Ring-ding-ding-ding-dingeringeding!\n"
                   "Gering-ding-ding-ding-dingeringeding!\n"
                   "Gering-ding-ding-ding-dingeringeding!" << std::endl;
      break;
    case TypeFox::GrayFox:
      std::cout << "Joff-tchoff-tchoffo-tchoffo-tchoff!\n"
                   "Tchoff-tchoff-tchoffo-tchoffo-tchoff!\n"
                   "Joff-tchoff-tchoffo-tchoffo-tchoff!" << std::endl;
      break;
    case TypeFox::SwiftFox:
      std::cout << "Jacha-chacha-chacha-chow!\n"
                   "Chacha-chacha-chacha-chow!\n"
                   "Chacha-chacha-chacha-chow!" << std::endl;
      break;
  }
}

Fox::Fox() : name(nullptr), type(TypeFox::ArcticFox), numberRabbitsEaten(0) {}

Fox::Fox(const char* name, TypeFox type, float mass, const char* sex, int age, const char* color)
    : Animal(mass, sex, color, age), name(nullptr), type(type), numberRabbitsEaten(0) {
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
}

Fox::Fox(const Fox& other) : Animal(other), type(other.type), numberRabbitsEaten(other.numberRabbitsEaten) {
  this->name = new char[strlen(other.name) + 1];
  strcpy(this->name, other.name);
}

Fox::Fox(Fox&& other): Animal(std::move(other)), name(other.name), type(other.type), numberRabbitsEaten(other.numberRabbitsEaten) {
  other.name = nullptr;
  other.numberRabbitsEaten = 0;
}

Fox::~Fox() {
  delete[] name;
}

Fox& Fox::operator=(const Fox& other) {
  if (this != &other) {
    Animal::operator=(other);
    delete[] name;
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    type = other.type;
    numberRabbitsEaten = other.numberRabbitsEaten;
  }
  return *this;
}

Fox& Fox::operator=(Fox&& other){
  if (this != &other) {
    Animal::operator=(std::move(other));
    delete[] name;
    name = other.name;
    other.name = nullptr;
    type = other.type;
    numberRabbitsEaten = other.numberRabbitsEaten;
    other.numberRabbitsEaten = 0;
  }
  return *this;
}

const char* Fox::GetName() const {
  return name;
}

TypeFox Fox::GetType() const {
  return type;
}

int Fox::GetNumberRabbitsEaten() const {
  return numberRabbitsEaten;
}

void Fox::SetName(const char* newName) {
  delete[] name;
  name = new char[strlen(newName) + 1];
  strcpy(name, newName);
}

void Fox::SetType(TypeFox newType) {
  type = newType;
}

void Fox::SetNumberRabbitsEaten(int newNumber) {
  numberRabbitsEaten = newNumber;
}

void Fox::Eat() {
  numberRabbitsEaten++;
}
