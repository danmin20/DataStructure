#ifndef USERTYPE_H
#define USERTYPE_H
#include"account.h"

class UserType
{
public:
    /**
    *	기본 생성자.
    */
    UserType() {
        ID = "";
        PW = "";
        name = "";
        birth = "";
        gender = "";
        acc = new Account();
    }

    /**
    *	기본 소멸자.
    */
    ~UserType() {}

    /**
    *	@brief	회원의 ID를 가져온다.
    *	@pre	회원의 ID가 설정되어 있어야 한다.
    *	@post	없음.
    *	@return	ID.
    */
    string GetID();

    /**
    *	@brief	회원의 비밀번호를 가져온다.
    *	@pre	회원의 비밀번호가 설정되어 있어야 한다.
    *	@post	없음.
    *	@return	PW.
    */
    string GetPW();

    /**
    *	@brief	회원의 이름을 가져온다.
    *	@pre	회원의 이름이 설정되어 있어야 한다.
    *	@post	없음.
    *	@return	name.
    */
    string GetName();

    /**
    *	@brief	회원의 생년월일을 가져온다.
    *	@pre	회원의 생년월일이 설정되어 있어야 한다.
    *	@post	없음.
    *	@return	birth.
    */
    string GetBirth();

    /**
    *	@brief	회원의 성별을 가져온다.
    *	@pre	회원의 성별이 설정되어 있어야 한다.
    *	@post	없음.
    *	@return	gender.
    */
    string GetGen();

    /**
    *	@brief  회원 ID가 설정된다.
    *	@pre	없음.
    *	@post	회원 ID가 설정된다.
    */
    void SetID(string id);

    /**
    *	@brief  회원 비밀번호가 설정된다.
    *	@pre	없음.
    *	@post	회원 비밀번호가 설정된다.
    */
    void SetPW(string pw);

    /**
    *	@brief  회원 정보가 설정된다.
    *	@pre	없음.
    *	@post	회원 정보가 설정된다.
    */
    void SetRecord(string id, string pw, string name, string birth, string gen);

    /**
    *	@brief  acc가 소멸된다.
    *	@pre	없음.
    *	@post	acc가 소멸된다.
    */
    void Del();

    /**
    *	@brief  acc가 실행된다.
    *	@pre	없음.
    *	@post	acc가 실행된다.
    */
    void AccountRun();

    /**
    *	@brief  회원 정보를 반환한다.
    *	@pre	없음.
    *	@post	회원 정보를 반환한다.
    */
    QString DisplayRecord();

    /**
    *	@brief  회원의 음악 정보를 반환한다.
    *	@pre	없음.
    *	@post	회원의 음악 정보를 반환한다.
    */
    QString DisplayMusic();

private:
    string ID;
    string PW;
    string name;
    string birth;
    string gender;
    Account *acc;
};


#endif
