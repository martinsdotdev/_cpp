#pragma once

#include <string>

#include "ICharacter.h"

class ICharacter;

class AMateria {
 public:
  AMateria();
  AMateria(const std::string& type);
  AMateria(const AMateria& other);
  AMateria& operator=(const AMateria& other);
  virtual ~AMateria();

  const std::string& getType() const;

  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);

 protected:
  std::string m_type;
};
