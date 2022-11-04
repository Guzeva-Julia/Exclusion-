/*Copyright (C) 2022 Huzieva Iyliia*/

/*У  завданні  реалізовані  функції  або  методи  повинні  генерувати відповідні  виключення.  
Обробку  виключень  потрібно  виконувати  головною  функцією, яка повинна демонструвати обробку 
всіх перехоплених  виключень. 
Функції, реалізовані в завданні, повинні  виконувати перевірку переданих параметрів  і  генерувати  
виключення  у  випадку  помилкових.  Усі  функції реалізуються в чотирьох варіантах: 
•  без специфікації виключень; 
•  зі специфікацією throw(); 
•  с конкретною специфікацією з відповідним стандартним виключенням; 
•  специфікація із власним реалізованим виключенням. 
Власне  виключення  повинне  бути  реалізоване  в  трьох  варіантах:  як порожній  клас,  як  незалежний  
клас  із  полями-параметрами  функції,  як спадкоємець від стандартного виключення з полями. Перехоплення й обробку 
виключень повинна виконувати головна функція. 
Варіант №6 
Функція обчислює суму геометричної прогресії.*/

#include<iostream>
#include<math.h>
#include<exception>
#include<cstdlib>

using namespace std;

void geometricProgression_1(float a, float b, float c) { //Реалізування функції без специфікації виключень.
    float s = (a * (1 - pow(b, c))) / (1 - c);
    cout << "Sum of progression`s members: " << s << endl;
}

void geometricProgression_2(float a, float b, float c) {  //Реалізування специфікації throw.
    try {
        if (a == 0)
            throw 1;
        if (b == 1)
            throw 2;
        if (c < 0)
            throw 3;

        float s = (a * (1 - pow(b, c))) / (1 - b);
        cout << "Sum of progression`s members: " << s << endl;
    }
    catch (int error) {    //Реалізування з конкретною специфікацією з відповідним стандартним виключенням.
        if (error == 1)
            cout << "First number of progressin equal to 0" << endl;//a
        if (error == 2)
            cout << "Progression denominator can`t be equal to 1" << endl;//b
        if (error == 3)
            cout << "Member number equal to 0" << endl;//c
    }
}

float geometricProgression_3(float a, float b, float c) { //Реалізування специфікації із власним реалізованим виключенням. 
    if (a == 0)
        throw runtime_error("First number of progressin equal to 0");
    if (b == 1)
        throw runtime_error("Progression denominator can`t be equal to 1");
    if (c < 0)
        throw runtime_error("Member number equal to 0");

    float s = (a * (1 - pow(b, c))) / (1 - b);
    return s;
}

int main() //Реалізування виключення в трьох варіантах.
{
    cout << "Variant number one: "; //Виключення як порожній клас.
    geometricProgression_1(20, 2, 3);

    cout << "Variant number two: "; //Виключення як незалежний  клас  із  полями - параметрами  функції.
    geometricProgression_2(20, 2, 3);

    cout << "Variant number three: "; //Виключення як спадкоємець від стандартного виключення з полями.
    try {
        float result = geometricProgression_3(20, 2, 3);
        cout << "Result equal to: " << result << endl;
    }
    catch (const overflow_error error) {
        cout << "Overflow error!" << error.what() << endl;
    }
    catch (const runtime_error error) {
        cout << "Runtime error!" << error.what() << endl;
    }
    catch (const exception error) {
        cout << "Exception!" << error.what() << endl;
    }
   
    system("pause");
    return 0;

}
