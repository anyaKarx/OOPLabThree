#include<iostream>
#include <string>

#include "InputValidation.h"
bool IsNotLetter(uint16_t symbol)
{
    bool isNumber = symbol < 1040,
    isSpecSymbol = symbol > 1103;
    return isNumber || isSpecSymbol;
}

template<typename valueType, typename isTheValueValidFunction>
valueType GetValidValueFromUser(std::wstring message, isTheValueValidFunction isTheValueValid)
{
    valueType value = 0;
    bool isInvalid = true;

    while (isInvalid)
    {
        std::wcout << message;
        std::wcin >> value;
        bool isStreamFail = std::wcin.fail();
        isInvalid = isStreamFail || !isTheValueValid(value) || std::wcin.peek() != L'\n';
        if (isInvalid)
        {
            if (isStreamFail)
                std::wcin.clear();

            std::wcout << L"«начение недопустимо, попробуйте еще раз:" << std::endl;
        }
        std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    }

    system("cls");
    return value;
}


std::wstring GetValidStringFromUser()
{
    std::wstring input;
    bool isCorrect = false;
    uint16_t spaceUnicode = 32;
    uint16_t dashUnicode = 45;
    uint16_t pointUnicode = 46;
    while (!isCorrect)
    {
        std::getline(std::wcin, input);
        isCorrect = true;
        for (size_t i = 0; i < input.length(); i++)
        {
            if (IsNotLetter((uint16_t)input[i])
                && ((uint16_t)input[i] != spaceUnicode
                    && ((uint16_t)input[i] != dashUnicode)
                    && ((uint16_t)input[i] != pointUnicode)))
            {
                std::wcout << L" ¬вод должен быть на русском €зыке и не"
                    << L"содержать посторонних символов "
                    <<L"(кроме точки, тире или пробела)." << std::endl;
                isCorrect = false;
                break;
            }
        }
    }

    return move(input);
};