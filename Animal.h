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
  Animal(float a_mass, const char* a_sex, const char* a_color, int a_age);
  Animal(const Animal& copy);
  Animal(Animal&& move);
  Animal &operator=(const Animal &other);
  Animal &operator=(Animal &&other);
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
  Yorkshire_terrier,
  Dachshund,
  Chihuahua,
  Bulldog,
  Husky,
  Corgi,
  Newfoundland,
  Chow_Chow,
  Rottweiler
};

class Dog: public Animal{
 private:
  Dog(char *d_name, Breed d_race, float d_mass, char *d_sex, char *d_color, int d_age);
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
  char* GetName();
  Breed GetRace();
  void SetName(char* newName);
  void SetRace(Breed newRace);
};

enum class TypeFox {
  ArcticFox,
  RedFox,
  FennecFox,
  GrayFox,
  SwiftFox
};

class Fox: public Animal{
 private:
  char* name;
  TypeFox type;
  int numberRabbitsEaten;
 public:
  void WhatDoesSay() override;
  Fox();  // Конструктор по умолчанию
  Fox(const char* name, TypeFox type, float mass, const char* sex, int age, const char* color);
  Fox(const Fox& other);  // Конструктор копирования
  Fox(Fox&& other);  // Конструктор перемещения
  ~Fox();
  Fox& operator=(const Fox& other);
  Fox& operator=(Fox&& other);
  const char* GetName() const;
  TypeFox GetType() const;
  int GetNumberRabbitsEaten() const;
  void SetName(const char* newName);
  void SetType(TypeFox newType);
  void SetNumberRabbitsEaten(int newNumber);
  void Eat();
};