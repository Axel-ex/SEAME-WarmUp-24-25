#pragma once

#include <string>

class Contact
{
    public:
        Contact(const std::string& name, const std::string& nickname,
                const std::string& phone_number);
        ~Contact(void);

        const std::string& getName() const;
        const std::string& getPhoneNb() const;
        const std::string& getNickname() const;

    private:
        std::string _name;
        std::string _phone_nb;
        std::string _nickname;
};

std::ostream &operator<<(std::ostream &ofs, const Contact &contact);
