#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Audio.hpp>
using namespace std;
int main(){
	int vib;
	srand( time(NULL));
	setlocale(LC_ALL, "RUS");

	sf::SoundBuffer correctBuffer;
	if (!correctBuffer.loadFromFile("fail.ogg")) {
		return -1; // Ошибка при загрузке файла
	}
	sf::Sound correctSound;
	correctSound.setBuffer(correctBuffer);

	sf::SoundBuffer correctBuffer2;
	if (!correctBuffer2.loadFromFile("win.ogg")) {
		return -1; // Ошибка при загрузке файла
	}
	sf::Sound correctSound2;
	correctSound2.setBuffer(correctBuffer2);

	cout << "\t\t\t\tИгра угадайка\nВыберите режим:\n[1]1-10\n[2]1-100\nВаш выбор ";
	cin >> vib;
	
		if (vib == 1) {
			int r, a;
			r = rand() % 10;
			do {
				cout << "Угадай число ";
				cin >> a;
				if (a == r) {
					cout << "Вы угадали!";
					correctSound2.play();
					break;
				}
				if (a == 0) break;
				
			} while (r != 0);
			if (a != r) {
				correctSound.play();
				cout << "Вы не угадали, загаданное число - " << r;

			}
		}
		if (vib == 2) {
			int r, a;
			r = rand() % 100;
			do {
			cout << "Угадай число ";
			cin >> a;
			if (a == r) {
				correctSound2.play();
				cout << "Вы угадали!";
				break;
			}
			if (a == 0) break;
			
			} while (r != 0);
			if (a != r) {
				correctSound.play();
				cout << "Вы не угадали, загаданное число - " << r;
			}
		}
		if (vib < 1 || vib>2) cout << "Неверный вод ";
		
}