#include "Animal.h"
#include <string.h>

Animal::Animal(): mass(0), sex(NULL), color(""), age(0){
}


Animal::Animal(float a_mass, char *a_sex, char *a_color, int a_age) {
  mass = a_mass;

  sex = new char[strlen(a_sex) + 1];
  strcpy(sex, a_sex);

  color = new char[strlen(a_color) + 1];
  strcpy(color, a_color);

  age = a_age;
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

void Dog::WhatDoesSay(){
  std::cout << "Woof! Woof!" << std::endl;
}

Dog::Dog() : name(NULL), race(Breed::Labrador){
}
Dog::Dog(char *d_name, Breed d_race, float d_mass, char* d_sex, char* d_color, int d_age) {
  Animal(d_mass, d_sex, d_color, d_age);

  name = new char[strlen(d_name) + 1];
  strcpy(name, d_name);

  race(d_race);
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
    delete[] name;
    name = new char[strlen(copy.name) + 1];
    strcpy(name, copy.name);
    race = copy.race;
  }
  return *this;
}



