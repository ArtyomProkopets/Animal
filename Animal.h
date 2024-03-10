#include <iostream>
#include <string.h>

using namespace std;

class Animal{
 private:
  float mass;
  char* sex;
  char* color;
  int age;

 public:
  Animal();
  Animal(float a_mass, char *a_sex, char *a_color, int a_age);
  Animal(const Animal& copy);
  Animal(Animal&& move);
  virtual ~Animal();
  float GetMass();
  char* GetSex();
  int GetAge();
  char* GetColor();
  void SetMass(float newMass);
  void SetSex(const char* newSex);
  void SetAge(int newAge);
  void SetColor(const char* newColor);
  virtual void WhatDoesSay();
};

enum class Breed {
  Labrador,
  Beagle,
  Bulldog,
  Poodle,
  GermanShepherd,
  Boxer,
  GoldenRetriever,
  SiberianHusky,
  Dachshund,
  ShihTzu
};

class Dog: public Animal{
 private:
  char* name;
  Breed race;
 public:
  void WhatDoesSay() override;
  Dog();
  Dog(char* name, char* race);
  Dog(const Dog& copy);
  Dog(Dog&& move);
  ~Dog();
  Dog& operator=(Dog &copy);
  Dog& operator=(Dog &&move);
  float GetName();
  char* GetRace();
  void SetName();
  void SetRace();
};

class Fox: public Animal{
 private:
  char* name;
  char* type;
  int numberRabbitsEaten;
 public:
  void WhatDoesSay() override;
  Fox(char* name, char* type);
  ~Fox();
  Fox& operator=(char &other);
  Fox& operator=(char &&other);
  char* GetName();
  char* GetType();
  int GetNumberRabbitsEaten();
  void SetName();
  void SetType();
  void SetNumberRabbitsEaten();
  void Eat();

};