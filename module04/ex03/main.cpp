#include "Character.h"
#include "Cure.h"
#include "ICharacter.h"
#include "IMateriaSource.h"
#include "Ice.h"
#include "MateriaSource.h"

int main() {
  {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
  }

  {
    IMateriaSource* ms = new MateriaSource();
    ms->learnMateria(new Ice());

    Character* c1 = new Character("Alice");
    c1->equip(ms->createMateria("ice"));

    Character* c2 = new Character(*c1);
    c2->use(0, *c1);

    delete c1;
    delete c2;
    delete ms;
  }
}
