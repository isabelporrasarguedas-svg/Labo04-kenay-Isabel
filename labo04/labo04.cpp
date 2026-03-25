#include <iostream>
#include "Squad.h"

using namespace std;

int main() {
    // 1) Crear un Squad con capacidad 3 y reclutar 5 guerreros
    Squad s1("Alpha", 3);
    Warrior* w1 = s1.recruit("Ares", "Tank", 80, 90, 800, 4);
    Warrior* w2 = s1.recruit("Loki", "Assassin", 95, 40, 400, 4);
    Warrior* w3 = s1.recruit("Merlin", "Mage", 70, 50, 300, 4);
    Warrior* w4 = s1.recruit("Hestia", "Support", 60, 60, 500, 4);
    Warrior* w5 = s1.recruit("Brutus", "Tank", 85, 80, 750, 4);

    // 2) Enseñar habilidades a al menos 3 guerreros (mínimo 2 habilidades por guerrero, distintos tipos)
    if (w1) {
        w1->learnSkill("Shield Bash", "Physical", 50, 10);
        w1->learnSkill("Fortify", "Healing", 30, 8);
    }
    if (w2) {
        w2->learnSkill("Backstab", "Physical", 80, 15);
        w2->learnSkill("Poison Cloud", "Magical", 45, 12);
    }
    if (w3) {
        w3->learnSkill("Fireball", "Magical", 90, 20);
        w3->learnSkill("Rejuvenate", "Healing", 40, 10);
    }

    // 3) Mostrar el Squad completo y las habilidades de al menos un guerrero
    cout << "--- Squad Alpha (initial) ---" << endl;
    s1.showSquad();
    cout << "\n--- Mostrar habilidades de Merlin ---" << endl;
    if (w3) w3->show();

    // 4) Ordenar por poder y mostrar el resultado
    s1.sortByPower();
    cout << "\n--- Squad Alpha (sorted by power) ---" << endl;
    s1.showSquad();

    // 5) Usar getByClass para filtrar una clase, mostrar los resultados y liberar el arreglo retornado
    int tankCount = 0;
    Warrior** tanks = s1.getByClass("Tank", tankCount);
    cout << "\n--- Tanks found: " << tankCount << " ---" << endl;
    if (tanks) {
        for (int i = 0; i < tankCount; i++) {
            if (tanks[i]) tanks[i]->show();
        }
        delete[] tanks; // liberar arreglo retornado
    }

    // 6) Dar de baja a un guerrero que tiene habilidades y mostrar el Squad actualizado
    cout << "\nDando de baja a 'Merlin'..." << endl;
    bool removed = s1.dismiss("Merlin");
    cout << "Merlin removed: " << (removed ? "true" : "false") << endl;
    cout << "\n--- Squad Alpha (after removal) ---" << endl;
    s1.showSquad();

    // 7) Crear un segundo Squad enemigo con 3 guerreros y habilidades
    Squad s2("Omega", 3);
    Warrior* e1 = s2.recruit("Nemesis", "Assassin", 90, 45, 420, 3);
    Warrior* e2 = s2.recruit("Gorgon", "Mage", 75, 55, 350, 3);
    Warrior* e3 = s2.recruit("Titan", "Tank", 80, 85, 900, 3);

    if (e1) { e1->learnSkill("Pierce", "Physical", 70, 14); e1->learnSkill("Shadow Bolt", "Magical", 50, 12); }
    if (e2) { e2->learnSkill("Ice Lance", "Magical", 80, 18); e2->learnSkill("Heal Pulse", "Healing", 35, 9); }
    if (e3) { e3->learnSkill("Crush", "Physical", 65, 13); e3->learnSkill("Stone Skin", "Healing", 25, 7); }

    // 8) Simular el combate entre ambos escuadrones y mostrar el resultado
    cout << "\n--- Simulacion de batalla ---" << endl;
    string winner = s1.simulateBattle(s2);
    cout << "Resultado: " << winner << endl;

    // 9) Intentar dar de baja a un guerrero inexistente (debe retornar false)
    cout << "\nIntentando dar de baja a 'NoName'..." << endl;
    bool removed2 = s1.dismiss("NoName");
    cout << "NoName removed: " << (removed2 ? "true" : "false") << endl;

    return 0;
}
