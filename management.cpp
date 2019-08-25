#include<iostream> //cout, cin,endl 등 기본 입출력 함수를 포함한 헤더파일이다.
#include<string> //문자열을 처리하는 string 클래스가 포함한 헤더파일이다. 
#include<iomanip> //flush 함수를 포함한 헤더파일이다.
#include <Windows.h> //Sleep 함수를 포함한 헤더파일이다.
using namespace std; //표준 네임스페이스를 사용


class Time_Oper //time, year, overtime, day과 같은 시간 파라메터값을 모아둔 클래스
{
	int time;
	int year;
	int overtime;
	int day;
public: // 기반클래스인 Time_Oper에서 쓰이는 public멤버변수를 초기화한다. 
	void SET_Day(int day) { // SET_Day의 기능을 하는 메소드를 정의한다.  
		this->day = day;
	}
	int GET_Day() { return day; } 
	void SET_Time(int time) { this->time = time; }
	int GET_Time() { return time; }
	void SET_Year(int year) { this->year = year; }
	int GET_Year() { return year; }
	void SET_Overtime(int overtime) { this->overtime = overtime; }
	int GET_Overtime() { return overtime; }
};
class Worker_Pay_Oper : protected Time_Oper { 
	//월급, 일급, 시급, 야근수당, 식비, 보너스 변수 모음 클래스
public:
	unsigned int pay_month;      //월급
	unsigned int pay_year;      //연봉
	unsigned int pay_day;        //일당
	unsigned int pay_hour;   //하루일한시간
	unsigned int pay_hour_pay;      //시급
	unsigned int pay_overtime;   //야근수당
	unsigned int pay_meal;      //식비
	unsigned int pay_bonus;      //보너스
	int pension;      //연금
	int insurance;     //보험
	int tax;         //소득세
	unsigned int real_pay;      //실수령액

	Worker_Pay_Oper() { //pay_hour_pay의 초기화 값을 지정. 이외의 것들은 밑에 메소드에서 초기화.
		/*	pay_month = 0;
		pay_year = GET_pay_month() * 12;
		pay_day = 0;*/
		pay_hour_pay = 8350; //2019 5월 현재 최저시급반영
		/*pay_overtime = 0;
		pay_meal = 0;
		pay_bonus = 0;
		pension = 0;
		insurance = 0;
		real_pay = 0;*/
	}

	//void SET_pay_month(int pay_month) { this->pay_month = pay_month; }
	void SET_pay_hour(int pay_hour) { this->pay_hour = pay_hour; }
	void SET_pay_day(int pay_day) { this->pay_day = pay_day; }
	void SET_pay_overtime(int pay_overtime) { this->pay_overtime = pay_overtime; }
	//void SET_pay_year(int pay_year) { this->pay_year = pay_year; }
	//void SET_pay_meal(int pay_meal) { this->pay_meal = pay_meal; }
	void SET_pay_bonus(int pay_bonus) { this->pay_bonus = pay_bonus; }
	void SET_pension(int pension) { this->pension = pension; }
	//void SET_insurance(int insurance) { this->insurance = insurance; }
	void SET_Tax(int tax) { this->tax = tax; }
	void SET_real_pay(int real_pay) { this->real_pay = real_pay; }

	int GET_pay_day() { return pay_day; }
	//int GET_pay_month() { return pay_month = pay_day * (pay_hour*pay_hour_pay); }
	int GET_pay_year() { return pay_year = pay_month * 12; }
	int GET_pay_overtime() { return pay_overtime; }
	int GET_pay_meal() { return pay_meal; }
	int GET_pay_bonus()const { return pay_bonus; }
	int GET_pension() { return pension; }
	int GET_insurance() { return insurance; }
	int GET_Tax() { return tax; }
	int GET_real_pay() { return real_pay; }
};
//사원 정보 객체 모음
class Worker_Info
{

	string name_worker;    //사원 이름
	string name_bank;      //은행 이름
	string address_worker;   //사원 주소
	string address_email;   //이메일

	int num_worker;   //사원번호   0000
	string birth;      //생년월일   19990101
	string data_phone;   //연락처      010-5431-9587
	string bank_num;   //계좌번호   

	typedef enum { 알바생, 비정규직, 정규직, }rank_worker; //typedef: sturct 키워드 없이 함수의 별칭을 rank_worker로 정의    

public:
	//setter ->
	void SET_name_worker(string name_worker) { this->name_worker = name_worker; }
	void SET_name_bank(string name_bank) { this->name_bank = name_bank; }
	void SET_address_worker(string address_worker) { this->address_worker = address_worker; }
	void SET_address_email(string address_email) { this->address_email = address_email; }
	//getter -> 
	string GET_name_worker()const { return name_worker; }
	string GET_name_bank()const { return name_bank; }
	string GET_address_worker()const { return address_worker; }
	string GET_address_email()const { return address_email; }

	//setter
	void SET_num_worker(int num_worker) { this->num_worker = num_worker; }
	void SET_birth(string birth) { this->birth = birth; }
	void SET_data_phone(string data_phone) { this->data_phone = data_phone; }
	void SET_bank_num(string bank_num) { this->bank_num = bank_num; }
	//getter
	int GET_num_worker() { return num_worker; }
	string GET_birth()const { return birth; }
	string GET_data_phone()const { return data_phone; }
	string GET_bank_num()const { return bank_num; }

};

class List {

public:
	Worker_Pay_Oper wp; //월급, 일급, 시급, 야근수당, 식비, 보너스 객체 모음 클래스 -> wp로 변수명 선언
	Worker_Info wi; //사원 정보 객체 모음 클래스 -> wi로 변수명 선언
	Time_Oper ti; //time, year, overtime, day 객체 모음 클래스 -> ti로 변수명 선언
};

class FullTime : public List {
public:
	FullTime* next; // 다음노드
	FullTime* head; //head 값 포인터 지정
	FullTime()
	{
		next = head = NULL;
	}

	int GET_pay_month() { return ti.GET_Day() * ti.GET_Time() * wp.pay_hour_pay; } //월급
	int GET_pay_year() { return GET_pay_month() * 12; }//연봉
	int GET_pay_overtime() { return ti.GET_Overtime() * (wp.pay_hour_pay * 1.5); }//초과수당
	int GET_pay_meal() { return ti.GET_Day() * 6000; }//식비
	int GET_pension() { return (int)GET_pay_month() * 0.045; } //연금
	int GET_insu() { return GET_helinsu() + GET_empinsu(); }//총보험
	int GET_helinsu() { return GET_pay_month() * 0.0323; } //건강보험
	int GET_empinsu() { return GET_pay_month() * 0.0065; } //고용보험
	int GET_Tax() { //세금: 소득분위별로 다르게 계산한다
		if (GET_pay_year() < 12000000) { //1200미만 소득분위
			wp.SET_Tax((int)(GET_pay_year() * 0.06) / 12); //결과값은 int 값으로 형변환
		}
		else if (GET_pay_year() > 12000000 && GET_pay_year() < 46000000) { //1200만원초과 4600만원미만 소득분위
			wp.SET_Tax((int)((GET_pay_year() * 0.15) - 1080000) / 12);
		}
		else if (GET_pay_year() > 46000000 && GET_pay_year() < 88000000) { //4600만원초과 8800만원미만 소득분위
			wp.SET_Tax((int)((GET_pay_year() * 0.24) - 5220000) / 12);
		}
		else if (GET_pay_year() > 88000000 && GET_pay_year() < 150000000) { //8800만원초과 1억5000만원미만 소득분위
			wp.SET_Tax((int)((GET_pay_year() * 0.35) - 14900000) / 12);
		}
		else if (GET_pay_year() > 150000000) { //1억5000만원초과 소득분위
			wp.SET_Tax((int)((GET_pay_year() * 0.38) - 19400000) / 12);
		}return wp.GET_Tax();
	}
	int GET_Total() { return  GET_pay_month() + GET_pay_overtime() + GET_pay_meal(); }
	int GET_Cost() { return GET_pension() + GET_insu() + GET_Tax(); }
	int GET_real_pay() { return GET_pay_month() + GET_pay_overtime() + GET_pay_meal() - GET_pension() - GET_insu() - GET_Tax(); } //실급여


};
class PartTime : public List {
public:
	PartTime* next; // 다음노드
	PartTime* head;
	PartTime()
	{
		next = head = NULL;
	}

	int GET_Ppay_month() { return (ti.GET_Day()) * ti.GET_Time() * wp.pay_hour_pay; }//월급
	int GET_Ppay_year() { return GET_Ppay_month() * 12; }//연봉
	int GET_Ppay_overtime() { return ti.GET_Overtime() * (wp.pay_hour_pay * 1.5); }//초과수당
	int GET_Ppay_meal() { return ti.GET_Day() * 6000; }//식비
	int GET_Pinsu() { return GET_Phelinsu() + GET_Pempinsu(); }//총보험
	int GET_Phelinsu() { return GET_Ppay_month() * 0.0323; } //건강보험
	int GET_Pempinsu() { return GET_Ppay_month() * 0.0065; } //고용보험
	int GET_PTax() {
		if (GET_Ppay_year() < 12000000) {
			wp.SET_Tax((int)(GET_Ppay_year() * 0.06) / 12);
		}
		else if (GET_Ppay_year() > 12000000 && GET_Ppay_year() < 46000000) {
			wp.SET_Tax((int)((GET_Ppay_year() * 0.15) - 1080000) / 12);
		}
		else if (GET_Ppay_year() > 46000000 && GET_Ppay_year() < 88000000) {
			wp.SET_Tax((int)((GET_Ppay_year() * 0.24) - 5220000) / 12);
		}
		else if (GET_Ppay_year() > 88000000 && GET_Ppay_year() < 150000000) {
			wp.SET_Tax((int)((GET_Ppay_year() * 0.35) - 14900000) / 12);
		}
		else if (GET_Ppay_year() > 150000000) {
			wp.SET_Tax((int)((GET_Ppay_year() * 0.38) - 19400000) / 12);
		}return wp.GET_Tax();
	}
	int GET_PTotal() { return  GET_Ppay_month() + GET_Ppay_overtime() + GET_Ppay_meal(); }
	int GET_PCost() { return  GET_Pinsu() + GET_PTax(); }//총공제
	int GET_Preal_pay() { return GET_Ppay_month() + GET_Ppay_overtime() + GET_Ppay_meal() - GET_Pinsu() - GET_PTax(); }


};
//-----------------------------------------------------------------------------------------------------------------------------------
class Master {
	FullTime ft;
	PartTime pt;
	string n;
	int m;
	int count1;
	int count2;
	//public:
	//	Master() {
	//		count = 1;
	//	}
public:
	FullTime* head, * del, * cur, * new1; //fulltime에 연결되는 포인터 변수값 정의
	PartTime* head2, * del2, * cur2, * new2;
	Master() { //Master 생성자선언
		count1 = 0;
		count2 = 0;
		head = del = cur = new1 = NULL; //포인터 값 초기화. 
		head2 = del2 = cur2 = new2 = NULL;
	}
	void fullinput() {
		count1 += 1; //사원번호를 자동으로 부여하기 위해 증감식을 씀
		if (head == NULL) {
			FullTime* new1 = new FullTime(); // 새로운 사원의 정보를 추기시키기 위해 새로운 노드를 생성한다
			head = new1; //드디어 생성노드를 가르키는 head포인터를 지정한다.
			new1->wi.SET_num_worker(count1); //count1에 해당되는 데이터 값을 입력한다.
			cout << " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
			cout << " ┃             정규직 사원번호 " << new1->wi.GET_num_worker() << "번을 입력합니다.             ┃\n";
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃               사원의 개인정보를 입력합니다.               ┃\n";
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷사원이름을 입력하세요 : ";
			cin >> n;
			new1->wi.SET_name_worker(n);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷생년월일을 입력하세요 ex. 19930222 : ";
			cin >> n;
			new1->wi.SET_birth(n);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷주소를 입력하세요 : ";
			cin >> n;
			new1->wi.SET_address_worker(n);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷이메일을 입력하세요 : ";
			cin >> n;
			new1->wi.SET_address_email(n);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷휴대폰번호를 입력하세요 : ";
			cin >> n;
			new1->wi.SET_data_phone(n);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷은행이름을 입력하세요 : ";
			cin >> n;
			new1->wi.SET_name_bank(n);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷계좌번호를 입력하세요 : ";
			cin >> n;
			new1->wi.SET_bank_num(n);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃               사원의 근로일수를 입력합니다.               ┃\n";
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷근로시간을 입력하세요 : ";
			cin >> m;
			new1->ti.SET_Time(m);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷근로일수를 입력하세요 : ";
			cin >> m;
			new1->ti.SET_Day(m);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷초과 근로시간을 입력하세요 : ";
			cin >> m;
			new1->ti.SET_Overtime(m);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷보너스를 입력하세요 : ";
			cin >> m;
			new1->wp.SET_pay_bonus(m);
			cout << " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
			Sleep(500);
		}
		else { //head !=NULL 인 경우 -> 사원번호가 1이 아닌경우. cur =head 이기 때문.
			//입력된게 있을  입력하는 정보
			FullTime* new1 = new FullTime(); //또 다시 노드 생성
			new1->wi.SET_num_worker(count1); //new1.함수 (함수호출식과 유사함)
			cout << " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
			cout << " ┃             정규직 사원번호 " << new1->wi.GET_num_worker() << "번을 입력합니다.             ┃\n";
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃               사원의 개인정보를 입력합니다.               ┃\n";
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷사원이름을 입력하세요 : ";
			cin >> n;
			new1->wi.SET_name_worker(n);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷생년월일을 입력하세요 ex. 19930222 : ";
			cin >> n;
			new1->wi.SET_birth(n);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷주소를 입력하세요 : ";
			cin >> n;
			new1->wi.SET_address_worker(n);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷이메일을 입력하세요 : ";
			cin >> n;
			new1->wi.SET_address_email(n);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷휴대폰번호를 입력하세요 : ";
			cin >> n;
			new1->wi.SET_data_phone(n);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷은행이름을 입력하세요 : ";
			cin >> n;
			new1->wi.SET_name_bank(n);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷계좌번호를 입력하세요 : ";
			cin >> n;
			new1->wi.SET_bank_num(n);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃               사원의 근로일수를 입력합니다.               ┃\n";
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷근로시간을 입력하세요 : ";
			cin >> m;
			new1->ti.SET_Time(m);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷근로일수를 입력하세요 : ";
			cin >> m;
			new1->ti.SET_Day(m);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷초과 근로시간을 입력하세요 : ";
			cin >> m;
			new1->ti.SET_Overtime(m);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷보너스를 입력하세요 : ";
			cin >> m;
			new1->wp.SET_pay_bonus(m);
			cout << " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
			Sleep(500);
			cur = head; //cur이라는 임의의포인터를 만들어 놓고 그 head값을 옮겨준다
			while (cur->next != NULL) { //다음 노드 -> 입력할 노드 가르키도록 하는 구문
				cur = cur->next; //다음 노드 이동
			}
			new1->next = NULL; //가르켰으면 이 구문에서 비우고 다른 노드로 넘어간다
			cur->next = new1; //현재 포인터 값을 다음 노드로 가르키게 한다. 

		}
	}
	void Partinput() {
		count2 += 1;

		if (head2 == NULL) {
			PartTime* new2 = new PartTime();
			head2 = new2;
			new2->wi.SET_num_worker(count2);
			cout << " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
			cout << " ┃            비정규직 사원번호 " << new2->wi.GET_num_worker() << "번을 입력합니다.            ┃\n";
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃               사원의 개인정보를 입력합니다.               ┃\n";
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷사원이름을 입력하세요 : ";
			cin >> n;
			new2->wi.SET_name_worker(n);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷생년월일을 입력하세요 ex. 19930222 : ";
			cin >> n;
			new2->wi.SET_birth(n);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷주소를 입력하세요 : ";
			cin >> n;
			new2->wi.SET_address_worker(n);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷이메일을 입력하세요 : ";
			cin >> n;
			new2->wi.SET_address_email(n);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷휴대폰번호를 입력하세요 : ";
			cin >> n;
			new2->wi.SET_data_phone(n);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷은행이름을 입력하세요 : ";
			cin >> n;
			new2->wi.SET_name_bank(n);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷계좌번호를 입력하세요 : ";
			cin >> n;
			new2->wi.SET_bank_num(n);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃               사원의 근로일수를 입력합니다.               ┃\n";
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷근로시간을 입력하세요 : ";
			cin >> m;
			new2->ti.SET_Time(m);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷근로일수를 입력하세요 : ";
			cin >> m;
			new2->ti.SET_Day(m);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷초과 근로시간을 입력하세요 : ";
			cin >> m;
			new2->ti.SET_Overtime(m);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷보너스를 입력하세요 : ";
			cin >> m;
			new2->wp.SET_pay_bonus(m);
			cout << " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
			Sleep(500);

		}
		else {

			PartTime* new2 = new PartTime();
			new2->wi.SET_num_worker(count2);
			cout << " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
			cout << " ┃             비정규직 사원번호 " << new2->wi.GET_num_worker() << "번을 입력합니다.           ┃\n";
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃               사원의 개인정보를 입력합니다.               ┃\n";
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷사원이름을 입력하세요 : ";
			cin >> n;
			new2->wi.SET_name_worker(n);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷생년월일을 입력하세요 ex. 19930222 : ";
			cin >> n;
			new2->wi.SET_birth(n);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷주소를 입력하세요 : ";
			cin >> n;
			new2->wi.SET_address_worker(n);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷이메일을 입력하세요 : ";
			cin >> n;
			new2->wi.SET_address_email(n);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷휴대폰번호를 입력하세요 : ";
			cin >> n;
			new2->wi.SET_data_phone(n);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷은행이름을 입력하세요 : ";
			cin >> n;
			new2->wi.SET_name_bank(n);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷계좌번호를 입력하세요 : ";
			cin >> n;
			new2->wi.SET_bank_num(n);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃               사원의 근로일수를 입력합니다.               ┃\n";
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷근로시간을 입력하세요 : ";
			cin >> m;
			new2->ti.SET_Time(m);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷근로일수를 입력하세요 : ";
			cin >> m;
			new2->ti.SET_Day(m);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷초과 근로시간을 입력하세요 : ";
			cin >> m;
			new2->ti.SET_Overtime(m);
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
			cout << " ┃ ▷보너스를 입력하세요 : ";
			cin >> m;
			new2->wp.SET_pay_bonus(m);
			cout << " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
			Sleep(500);
			cur2 = head2;
			while (cur2->next != NULL) {
				cur2 = cur2->next; //다음 노드 이동
			}
			new2->next = cur2->next;
			cur2->next = new2;
		}

	}
	//---------------------------------------------------------------------------------------------------------------------------------------------------
	void FullOutput()
	{
		if (head == NULL) { //입력된게 하나도 없을 경우에 이걸 출력하고
			cout << "                ※※※※※※※※※※※※※※※※※※\n";
			cout << "                ※    정보가 존재하지 않습니다!   ※\n";
			cout << "                ※※※※※※※※※※※※※※※※※※\n\n";
		}
		else { //입력된게 있을 경우에 이걸 출력한다
			cur = head; //head값 복사함
			while (cur != NULL) //만약 5번까지 입력되어있으면 1~5까지 순차적으로 전체 출력(반복문) cur !=NULL  <- 데이터가 있으면 반복적으로 데이더를 출력하고 없으면 끝남
			{
				cout << " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
				cout << " ┃             정규직 사원번호 " << cur->wi.GET_num_worker() << "번을 출력합니다.             ┃\n";
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃                  개     인     정     보                  ┃\n";
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃ ▷사원이름 : " << cur->wi.GET_name_worker() << endl;
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃ ▷생년월일 : " << cur->wi.GET_birth() << endl;
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃ ▷주    소 : " << cur->wi.GET_address_worker() << endl;
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃ ▷이 메 일 : " << cur->wi.GET_address_email() << endl;
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃ ▷휴대폰번호 : " << cur->wi.GET_data_phone() << endl;
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃ ▷은행이름 : " << cur->wi.GET_name_bank() << endl;
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃ ▷계좌번호 : " << cur->wi.GET_bank_num() << endl;
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃                  급     여     정     보                  ┃\n";
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃ ▷월급 : " << cur->FullTime::GET_pay_month() << " 원" << endl;
				cout << " ┃    ※ 시급 : " << cur->wp.pay_hour_pay << " 원" << endl;
				cout << " ┃    ※ 일한시간 : : " << cur->ti.GET_Time() << " 시간" << endl;
				cout << " ┃    ※ 출근일수 : " << cur->ti.GET_Day() << " 일" << endl;
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃ ▷초과수당 : " << cur->FullTime::GET_pay_overtime() << " 원" << endl;
				cout << " ┃    ※ 초과근무시급(시급 x 1.5) : " << cur->wp.pay_hour_pay * 1.5 << " 원" << endl;
				cout << " ┃    ※ 초과근무시간 : " << cur->ti.GET_Overtime() << " 시간" << endl;
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃ ▷식비(출근일수 * 6000) : " << cur->FullTime::GET_pay_meal() << " 원" << endl;
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃ ▷보너스 : " << cur->wp.GET_pay_bonus() << " 원" << endl;
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃                  공     제     정     보                  ┃\n";
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃ ▷연금(월급 x 0.045) : " << cur->FullTime::GET_pension() << " 원" << endl;
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃ ▷보험 : " << cur->FullTime::GET_insu() << " 원" << endl;
				cout << " ┃    ※ 건강보험(월급 x 0.0306) : " << cur->GET_helinsu() << " 원" << endl;
				cout << " ┃    ※ 고용보험(월급 x 0.0065) : " << cur->GET_empinsu() << " 원" << endl;
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃ ▷세금 : " << cur->FullTime::GET_Tax() << " 원" << endl;
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃                  최     종     정     보                  ┃\n";
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃ ▷총 급여 : " << cur->FullTime::GET_Total() << " 원" << endl;
				cout << " ┃ ▷총 공제 : " << cur->FullTime::GET_Cost() << " 원" << endl;
				cout << " ┃ ▷실 수령 : " << cur->FullTime::GET_real_pay() << " 원" << endl;
				cout << " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
				cout << "〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n";
				cur = cur->next;
			}
		}
	}
	void PartOutput()
	{
		if (head2 == NULL) {
			cout << "                ※※※※※※※※※※※※※※※※※※\n";
			cout << "                ※    정보가 존재하지 않습니다!   ※\n";
			cout << "                ※※※※※※※※※※※※※※※※※※\n\n";
		}
		else {
			cur2 = head2;
			while (cur2 != NULL)
			{
				cout << " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
				cout << " ┃             비정규직 사원번호 " << cur2->wi.GET_num_worker() << "번을 출력합니다.           ┃\n";
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃                  개     인     정     보                  ┃\n";
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃ ▷사원이름 : " << cur2->wi.GET_name_worker() << endl;
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃ ▷생년월일 : " << cur2->wi.GET_birth() << endl;
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃ ▷주    소 : " << cur2->wi.GET_address_worker() << endl;
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃ ▷이 메 일 : " << cur2->wi.GET_address_email() << endl;
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃ ▷휴대폰번호 : " << cur2->wi.GET_data_phone() << endl;
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃ ▷은행이름 : " << cur2->wi.GET_name_bank() << endl;
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃ ▷계좌번호 : " << cur2->wi.GET_bank_num() << endl;
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃                  급     여     정     보                  ┃\n";
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃ ▷월급 : " << cur2->PartTime::GET_Ppay_month() << " 원" << endl;
				cout << " ┃    ※ 시급 : " << cur2->wp.pay_hour_pay << " 원" << endl;
				cout << " ┃    ※ 근로시간 : : " << cur2->ti.GET_Time() << " 시간" << endl;
				cout << " ┃    ※ 출근일수 : " << cur2->ti.GET_Day() << " 일" << endl;
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃ ▷초과수당 : " << cur2->PartTime::GET_Ppay_overtime() << " 원" << endl;
				cout << " ┃    ※ 초과근무시급(시급 x 1.5) : " << cur2->wp.pay_hour_pay * 1.5 << " 원" << endl;
				cout << " ┃    ※ 초과근무시간 : " << cur2->ti.GET_Overtime() << " 시간" << endl;
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃ ▷식비(출근일수 * 6000) : " << cur2->PartTime::GET_Ppay_meal() << " 원" << endl;
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃ ▷보너스 : " << cur2->wp.GET_pay_bonus() << " 원" << endl;
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃                  공     제     정     보                  ┃\n";
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃ ▷보험 : " << cur2->PartTime::GET_Pinsu() << " 원" << endl;
				cout << " ┃    ※ 건강보험(월급 x 0.0306) : " << cur2->GET_Phelinsu() << " 원" << endl;
				cout << " ┃    ※ 고용보험(월급 x 0.0065) : " << cur2->GET_Pempinsu() << " 원" << endl;
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃ ▷세금 : " << cur2->PartTime::GET_PTax() << " 원" << endl;
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃                  최     종     정     보                  ┃\n";
				cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
				cout << " ┃ ▷총 급여 : " << cur2->PartTime::GET_PTotal() << " 원" << endl;
				cout << " ┃ ▷총 공제 : " << cur2->PartTime::GET_PCost() << " 원" << endl;
				cout << " ┃ ▷실 수령 : " << cur2->PartTime::GET_Preal_pay() << " 원" << endl;
				cout << " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
				cout << "〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n";
				cur2 = cur2->next;
			}
		}
	}
	//-------------------------------------------------------------------------------------------------------------------------------------------
	void Fulldele() {
		int comp;
		//cur = head->next; 
		if (head == NULL) {
			cout << "                ※※※※※※※※※※※※※※※※※※\n";
			cout << "                ※    정보가 존재하지 않습니다!   ※\n";
			cout << "                ※※※※※※※※※※※※※※※※※※\n\n";
		}
		else {

			cout << " ▶삭제 할 사원번호를 입력하세요 : ";
			cin >> comp;
			cur = head;
			while (1) {
				if (cur == NULL) {
					system("cls");
					cout << "                ※※※※※※※※※※※※※※※※※※\n";
					cout << "                ※    정보가 존재하지 않습니다!   ※\n";
					cout << "                ※※※※※※※※※※※※※※※※※※\n\n";
					break;
				}
				else {
					if (comp == cur->wi.GET_num_worker() && cur == head) {
						head = head->next;
						delete(cur);
						system("cls");
						cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
						cout << "                  ☆ 성공적으로 삭제되었습니다! ★\n";
						cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
						break;
					}
					else if (comp == cur->wi.GET_num_worker() && cur->next == NULL) {
						del = cur;
						cur = head;
						while (cur->next != del) {
							cur = cur->next;
						}
						cur->next = NULL;
						delete(del);
						system("cls");
						cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
						cout << "                  ☆ 성공적으로 삭제되었습니다! ★\n";
						cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
						break;
					}
					else if (cur->wi.GET_num_worker() == comp && cur->next != NULL) {
						del = cur;
						cur = head;
						while (cur->next != del) {
							cur = cur->next;
						}
						cur->next = del->next;
						del->next = NULL;
						delete(del);
						system("cls");
						cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
						cout << "                  ☆ 성공적으로 삭제되었습니다! ★\n";
						cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
						break;
					}
				}
				cur = cur->next;

			}
		}
	}

	void Partdele() {
		int comp2;
		//cur = head->next;
		if (head2 == NULL) {
			cout << "                ※※※※※※※※※※※※※※※※※※\n";
			cout << "                ※    정보가 존재하지 않습니다!   ※\n";
			cout << "                ※※※※※※※※※※※※※※※※※※\n\n";
		}
		else {

			cout << " ▶삭제 할 사원번호를 입력하세요 : ";
			cin >> comp2;
			cur2 = head2;
			while (1) {
				if (cur2 == NULL) {
					system("cls");
					cout << "                ※※※※※※※※※※※※※※※※※※\n";
					cout << "                ※    정보가 존재하지 않습니다!   ※\n";
					cout << "                ※※※※※※※※※※※※※※※※※※\n\n";
					break;
				}
				else {
					if (comp2 == cur2->wi.GET_num_worker() && cur2 == head2) {
						head2 = head2->next;
						delete(cur2);
						system("cls");
						cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
						cout << "                  ☆ 성공적으로 삭제되었습니다! ★\n";
						cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
						break;
					}
					else if (comp2 == cur2->wi.GET_num_worker() && cur2->next == NULL) {
						del2 = cur2;
						cur2 = head2;
						while (cur2->next != del2) {
							cur2 = cur2->next;
						}
						cur2->next = NULL;
						delete(del2);
						system("cls");
						cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
						cout << "                  ☆ 성공적으로 삭제되었습니다! ★\n";
						cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
						break;
					}
					else if (cur2->wi.GET_num_worker() == comp2 && cur2->next != NULL) {
						del2 = cur2;
						cur2 = head2;
						while (cur2->next != del2) {
							cur2 = cur2->next;
						}
						cur2->next = del2->next;
						del2->next = NULL;
						delete(del2);
						system("cls");
						cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
						cout << "                  ☆ 성공적으로 삭제되었습니다! ★\n";
						cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
						break;
					}
				}
				cur2 = cur2->next;
			}
		}
	}
	//-------------------------------------------------------------------------------------------------------------------------------------------
	void Fullcorrect() {
		int cor1;
		string fix;

		//cur = head->next;
		if (head == NULL) {
			system("cls");
			cout << "                ※※※※※※※※※※※※※※※※※※\n";
			cout << "                ※    정보가 존재하지 않습니다!   ※\n";
			cout << "                ※※※※※※※※※※※※※※※※※※\n\n";
		}
		else {
			cout << "\n";
			cout << " ▶수정 할 사원번호를 입력하세요 : ";
			cin >> cor1;
			system("cls");
			cur = head;
			while (1) {
				if (cur == NULL) {
					system("cls");
					cout << "                ※※※※※※※※※※※※※※※※※※\n";
					cout << "                ※    정보가 존재하지 않습니다!   ※\n";
					cout << "                ※※※※※※※※※※※※※※※※※※\n\n";
					break;
				}
				else {
					if (cor1 == cur->wi.GET_num_worker()) {
						cout << " ▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n";
						cout << " ▩       정규직 수정메뉴입니다.     ▩\n";
						cout << " ▩    수정할 정보를 입력해주세요!   ▩\n";
						cout << " ▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n";
						cout << " ▩         개   인   정   보        ▩\n";
						cout << " ▩〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓▩\n";
						cout << " ▩※사원번호※ " << cur->wi.GET_num_worker() << endl;
						cout << " ▩▷사원이름◁ : " << cur->wi.GET_name_worker() << endl;
						cout << " ▩▷생년월일◁ : " << cur->wi.GET_birth() << endl;
						cout << " ▩▷주    소◁ : " << cur->wi.GET_address_worker() << endl;
						cout << " ▩▷이 메 일◁ : " << cur->wi.GET_address_email() << endl;
						cout << " ▩▷휴대폰번호◁ : " << cur->wi.GET_data_phone() << endl;
						cout << " ▩▷은행이름◁ : " << cur->wi.GET_name_bank() << endl;
						cout << " ▩▷계좌번호◁: " << cur->wi.GET_bank_num() << endl;
						cout << " ▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n";
						cout << " ▩         급   여   정   보        ▩\n";
						cout << " ▩〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓▩\n";
						cout << " ▩▷근로시간◁ : " << cur->ti.GET_Time() << endl;
						cout << " ▩▷근로일수◁ : " << cur->ti.GET_Day() << endl;
						cout << " ▩▷초과시간◁ : " << cur->ti.GET_Overtime() << endl;
						cout << " ▩▷보 너 스◁ : " << cur->wp.GET_pay_bonus() << endl;
						cout << " ▩〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓▩\n";
						cout << " ▶수정할 ▷ ◁ 안의 내용을 정확히 입력해주세요 : ";
						cin >> fix;
						if (fix.compare("사원이름") == 0) {
							cout << " ▶현재 내용입니다 :" << cur->wi.GET_name_worker() << endl;
							cout << " ▶수정할 내용을 입력해주세요 : ";
							cin >> n;
							cur->wi.SET_name_worker(n);
							system("cls");
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							cout << "                  ☆ 성공적으로 수정되었습니다! ★\n";
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							break;
						}
						else if (fix.compare("생년월일") == 0) {
							cout << " ▶현재 내용입니다 :" << cur->wi.GET_birth() << endl;
							cout << " ▶수정할 내용을 입력해주세요 : ";
							cin >> n;
							cur->wi.SET_birth(n);
							system("cls");
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							cout << "                  ☆ 성공적으로 수정되었습니다! ★\n";
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							break;
						}
						else if (fix.compare("주소") == 0) {
							cout << " ▶현재 내용입니다 :" << cur->wi.GET_address_worker() << endl;
							cout << " ▶수정할 내용을 입력해주세요 : ";
							cin >> n;
							cur->wi.SET_address_worker(n);
							system("cls");
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							cout << "                  ☆ 성공적으로 수정되었습니다! ★\n";
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							break;
						}
						else if (fix.compare("이메일") == 0) {
							cout << " ▶현재 내용입니다 :" << cur->wi.GET_address_email() << endl;
							cout << " ▶수정할 내용을 입력해주세요 : ";
							cin >> n;
							cur->wi.SET_address_email(n);
							system("cls");
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							cout << "                  ☆ 성공적으로 수정되었습니다! ★\n";
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							break;
						}
						else if (fix.compare("휴대폰번호") == 0) {
							cout << " ▶현재 내용입니다 :" << cur->wi.GET_data_phone() << endl;
							cout << " ▶수정할 내용을 입력해주세요 : ";
							cin >> n;
							cur->wi.SET_data_phone(n);
							system("cls");
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							cout << "                  ☆ 성공적으로 수정되었습니다! ★\n";
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							break;
						}
						else if (fix.compare("은행이름") == 0) {
							cout << " ▶현재 내용입니다 :" << cur->wi.GET_name_bank() << endl;
							cout << " ▶수정할 내용을 입력해주세요 : ";
							cin >> n;
							cur->wi.SET_name_bank(n);
							system("cls");
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							cout << "                  ☆ 성공적으로 수정되었습니다! ★\n";
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							break;
						}
						else if (fix.compare("계좌번호") == 0) {
							cout << " ▶현재 내용입니다 :" << cur->wi.GET_bank_num() << endl;
							cout << " ▶수정할 내용을 입력해주세요 : ";
							cin >> n;
							cur->wi.SET_bank_num(n);
							system("cls");
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							cout << "                  ☆ 성공적으로 수정되었습니다! ★\n";
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							break;
						}
						else if (fix.compare("근로시간") == 0) {
							cout << " ▶현재 내용입니다 :" << cur->ti.GET_Time() << endl;
							cout << " ▶수정할 내용을 입력해주세요 : ";
							cin >> m;
							cur->ti.SET_Time(m);
							system("cls");
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							cout << "                  ☆ 성공적으로 수정되었습니다! ★\n";
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							break;
						}
						else if (fix.compare("근로일수") == 0) {
							cout << " ▶현재 내용입니다 :" << cur->ti.GET_Day() << endl;
							cout << " ▶수정할 내용을 입력해주세요 : ";
							cin >> m;
							cur->ti.SET_Day(m);
							system("cls");
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							cout << "                  ☆ 성공적으로 수정되었습니다! ★\n";
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							break;
						}
						else if (fix.compare("초과시간") == 0) {
							cout << " ▶현재 내용입니다 :" << cur->ti.GET_Overtime() << endl;
							cout << " ▶수정할 내용을 입력해주세요 : ";
							cin >> m;
							cur->ti.SET_Overtime(m);
							system("cls");
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							cout << "                  ☆ 성공적으로 수정되었습니다! ★\n";
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							break;
						}
						else if (fix.compare("보너스") == 0) {
							cout << " ▶현재 내용입니다 :" << cur->wp.GET_pay_bonus() << endl;
							cout << " ▶수정할 내용을 입력해주세요 : ";
							cin >> m;
							cur->wp.SET_pay_bonus(m);
							system("cls");
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							cout << "                  ☆ 성공적으로 수정되었습니다! ★\n";
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							break;
						}
						else {
							system("cls");
							cout << "             ※※※※※※※※※※※※※※※※※※※※※※\n";
							cout << "             ※    수정할 정보를 정확히 입력해주세요!  ※\n";
							cout << "             ※※※※※※※※※※※※※※※※※※※※※※\n\n";
							break;
						}
					}
				}
				cur = cur->next;
			}
		}

	}

	void Partcorrect() {
		int cor2;
		string fix2;

		//cur = head->next;
		if (head2 == NULL) {
			system("cls");
			cout << "                ※※※※※※※※※※※※※※※※※※\n";
			cout << "                ※    정보가 존재하지 않습니다!   ※\n";
			cout << "                ※※※※※※※※※※※※※※※※※※\n\n";
		}
		else {
			cout << "\n";
			cout << " ▶수정 할 사원번호를 입력하세요 : ";
			cin >> cor2;
			system("cls");
			cur2 = head2;
			while (1) {
				if (cur2 == NULL) {
					system("cls");
					cout << "                ※※※※※※※※※※※※※※※※※※\n";
					cout << "                ※    정보가 존재하지 않습니다!   ※\n";
					cout << "                ※※※※※※※※※※※※※※※※※※\n\n";
					break;
				}
				else {
					if (cor2 == cur2->wi.GET_num_worker()) {
						cout << " ▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n";
						cout << " ▩      비정규직 수정메뉴입니다.    ▩\n";
						cout << " ▩    수정할 정보를 입력해주세요!   ▩\n";
						cout << " ▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n";
						cout << " ▩※사원번호※ " << cur2->wi.GET_num_worker() << endl;
						cout << " ▩▷사원이름◁ : " << cur2->wi.GET_name_worker() << endl;
						cout << " ▩▷생년월일◁ : " << cur2->wi.GET_birth() << endl;
						cout << " ▩▷주    소◁ : " << cur2->wi.GET_address_worker() << endl;
						cout << " ▩▷이 메 일◁ : " << cur2->wi.GET_address_email() << endl;
						cout << " ▩▷휴대폰번호◁ : " << cur2->wi.GET_data_phone() << endl;
						cout << " ▩▷은행이름◁ : " << cur2->wi.GET_name_bank() << endl;
						cout << " ▩▷계좌번호◁: " << cur2->wi.GET_bank_num() << endl;
						cout << " ▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n";
						cout << " ▩         급   여   정   보        ▩\n";
						cout << " ▩〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓▩\n";
						cout << " ▩▷근로시간◁ : " << cur2->ti.GET_Time() << endl;
						cout << " ▩▷근로일수◁ : " << cur2->ti.GET_Day() << endl;
						cout << " ▩▷초과시간◁ : " << cur2->ti.GET_Overtime() << endl;
						cout << " ▩▷보 너 스◁ : " << cur2->wp.GET_pay_bonus() << endl;
						cout << " ▩〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓▩\n";
						cout << " ▶수정할 ▷ ◁ 안의 내용을 정확히 입력해주세요 : ";
						cin >> fix2;
						if (fix2.compare("사원이름") == 0) {
							cout << " ▶현재 내용입니다 :" << cur2->wi.GET_name_worker() << endl;
							cout << " ▶수정할 내용을 입력해주세요 : ";
							cin >> n;
							cur2->wi.SET_name_worker(n);
							system("cls");
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							cout << "                  ☆ 성공적으로 수정되었습니다! ★\n";
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							break;
						}
						else if (fix2.compare("생년월일") == 0) {
							cout << " ▶현재 내용입니다 :" << cur2->wi.GET_birth() << endl;
							cout << " ▶수정할 내용을 입력해주세요 : ";
							cin >> n;
							cur2->wi.SET_birth(n);
							system("cls");
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							cout << "                  ☆ 성공적으로 수정되었습니다! ★\n";
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							break;
						}
						else if (fix2.compare("주소") == 0) {
							cout << " ▶현재 내용입니다 :" << cur2->wi.GET_address_worker() << endl;
							cout << " ▶수정할 내용을 입력해주세요 : ";
							cin >> n;
							cur2->wi.SET_address_worker(n);
							system("cls");
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							cout << "                  ☆ 성공적으로 수정되었습니다! ★\n";
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							break;
						}
						else if (fix2.compare("이메일") == 0) {
							cout << " ▶현재 내용입니다 :" << cur2->wi.GET_address_email() << endl;
							cout << " ▶수정할 내용을 입력해주세요 : ";
							cin >> n;
							cur2->wi.SET_address_email(n);
							system("cls");
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							cout << "                  ☆ 성공적으로 수정되었습니다! ★\n";
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							break;
						}
						else if (fix2.compare("휴대폰번호") == 0) {
							cout << " ▶현재 내용입니다 :" << cur2->wi.GET_data_phone() << endl;
							cout << " ▶수정할 내용을 입력해주세요 : ";
							cin >> n;
							cur2->wi.SET_data_phone(n);
							system("cls");
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							cout << "                  ☆ 성공적으로 수정되었습니다! ★\n";
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							break;
						}
						else if (fix2.compare("은행이름") == 0) {
							cout << " ▶현재 내용입니다 :" << cur2->wi.GET_name_bank() << endl;
							cout << " ▶수정할 내용을 입력해주세요 : ";
							cin >> n;
							cur2->wi.SET_name_bank(n);
							system("cls");
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							cout << "                  ☆ 성공적으로 수정되었습니다! ★\n";
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							break;
						}
						else if (fix2.compare("계좌번호") == 0) {
							cout << " ▶현재 내용입니다 :" << cur2->wi.GET_bank_num() << endl;
							cout << " ▶수정할 내용을 입력해주세요 : ";
							cin >> n;
							cur2->wi.SET_bank_num(n);
							system("cls");
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							cout << "                  ☆ 성공적으로 수정되었습니다! ★\n";
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							break;
						}
						else if (fix2.compare("근로시간") == 0) {
							cout << " ▶현재 내용입니다 :" << cur2->ti.GET_Time() << endl;
							cout << " ▶수정할 내용을 입력해주세요 : ";
							cin >> m;
							cur2->ti.SET_Time(m);
							system("cls");
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							cout << "                  ☆ 성공적으로 수정되었습니다! ★\n";
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							break;
						}
						else if (fix2.compare("근로일수") == 0) {
							cout << " ▶현재 내용입니다 :" << cur2->ti.GET_Day() << endl;
							cout << " ▶수정할 내용을 입력해주세요 : ";
							cin >> m;
							cur2->ti.SET_Day(m);
							system("cls");
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							cout << "                  ☆ 성공적으로 수정되었습니다! ★\n";
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							break;
						}
						else if (fix2.compare("초과시간") == 0) {
							cout << " ▶현재 내용입니다 :" << cur2->ti.GET_Overtime() << endl;
							cout << " ▶수정할 내용을 입력해주세요 : ";
							cin >> m;
							cur2->ti.SET_Overtime(m);
							system("cls");
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							cout << "                  ☆ 성공적으로 수정되었습니다! ★\n";
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							break;
						}
						else if (fix2.compare("보너스") == 0) {
							cout << " ▶현재 내용입니다 :" << cur2->wp.GET_pay_bonus() << endl;
							cout << " ▶수정할 내용을 입력해주세요 : ";
							cin >> m;
							cur2->wp.SET_pay_bonus(m);
							system("cls");
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							cout << "                  ☆ 성공적으로 수정되었습니다! ★\n";
							cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
							break;
						}
						else {
							system("cls");
							cout << "             ※※※※※※※※※※※※※※※※※※※※※※\n";
							cout << "             ※    수정할 정보를 정확히 입력해주세요!  ※\n";
							cout << "             ※※※※※※※※※※※※※※※※※※※※※※\n\n";
							break;
						}
					}
				}
				cur2 = cur2->next;
			}
		}

	}
	//---------------------------------------------------------------------------------------------------------------------------
	void Fullsearch()
	{
		int ser;
		if (head == NULL) {
			cout << "                ※※※※※※※※※※※※※※※※※※\n";
			cout << "                ※    정보가 존재하지 않습니다!   ※\n";
			cout << "                ※※※※※※※※※※※※※※※※※※\n\n";
		}
		else {

			cout << " ▶검색할 사원번호를 입력하세요 : ";
			cin >> ser;
			system("cls");
			cur = head;
			while (1) {
				if (cur == NULL) {
					system("cls");
					cout << "                ※※※※※※※※※※※※※※※※※※\n";
					cout << "                ※    정보가 존재하지 않습니다!   ※\n";
					cout << "                ※※※※※※※※※※※※※※※※※※\n\n";
					break;
				}
				else {
					if (ser == cur->wi.GET_num_worker()) {
						cout << " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
						cout << " ┃             정규직 사원번호 " << cur->wi.GET_num_worker() << "번을 출력합니다.             ┃\n";
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃                  개     인     정     보                  ┃\n";
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃ ▷사원이름 : " << cur->wi.GET_name_worker() << endl;
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃ ▷생년월일 : " << cur->wi.GET_birth() << endl;
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃ ▷주    소 : " << cur->wi.GET_address_worker() << endl;
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃ ▷이 메 일 : " << cur->wi.GET_address_email() << endl;
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃ ▷휴대폰번호 : " << cur->wi.GET_data_phone() << endl;
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃ ▷은행이름 : " << cur->wi.GET_name_bank() << endl;
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃ ▷계좌번호 : " << cur->wi.GET_bank_num() << endl;
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃                  급     여     정     보                  ┃\n";
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃ ▷월급 : " << cur->FullTime::GET_pay_month() << " 원" << endl;
						cout << " ┃    ※ 시급 : " << cur->wp.pay_hour_pay << " 원" << endl;
						cout << " ┃    ※ 일한시간 : : " << cur->ti.GET_Time() << " 시간" << endl;
						cout << " ┃    ※ 출근일수 : " << cur->ti.GET_Day() << " 일" << endl;
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃ ▷초과수당 : " << cur->FullTime::GET_pay_overtime() << endl;
						cout << " ┃    ※ 초과근무시급(시급 x 1.5) : " << cur->wp.pay_hour_pay * 1.5 << " 원" << endl;
						cout << " ┃    ※ 초과근무시간 : " << cur->ti.GET_Overtime() << " 시간" << endl;
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃ ▷식비 : " << cur->FullTime::GET_pay_meal() << " 원" << endl;
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃ ▷보너스 : " << cur->wp.GET_pay_bonus() << " 원" << endl;
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃                  공     제     정     보                  ┃\n";
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃ ▷연금(월급 x 0.045) : " << cur->FullTime::GET_pension() << " 원" << endl;
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃ ▷보험 : " << cur->FullTime::GET_insu() << endl;
						cout << " ┃    ※ 건강보험(월급 x 0.0306) : " << cur->GET_helinsu() << " 원" << endl;
						cout << " ┃    ※ 고용보험(월급 x 0.0065) : " << cur->GET_empinsu() << " 원" << endl;
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃ ▷세금 : " << cur->FullTime::GET_Tax() << endl;
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃                  최     종     정     보                  ┃\n";
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃ ▷총 급여 : " << cur->FullTime::GET_Total() << " 원" << endl;
						cout << " ┃ ▷총 공제 : " << cur->FullTime::GET_Cost() << " 원" << endl;
						cout << " ┃ ▷실 수령 : " << cur->FullTime::GET_real_pay() << " 원" << endl;
						cout << " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
						cout << "〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n";
						break;
					}
					cur = cur->next;
				}
			}
		}
	}
	void Partsearch()
	{
		int ser2;
		if (head2 == NULL) {
			cout << "                ※※※※※※※※※※※※※※※※※※\n";
			cout << "                ※    정보가 존재하지 않습니다!   ※\n";
			cout << "                ※※※※※※※※※※※※※※※※※※\n\n";
		}
		else {

			cout << " ▶검색할 사원번호를 입력하세요 : ";
			cin >> ser2;
			system("cls");
			cur2 = head2;
			while (1) {
				if (cur2 == NULL) {
					system("cls");
					cout << "                ※※※※※※※※※※※※※※※※※※\n";
					cout << "                ※    정보가 존재하지 않습니다!   ※\n";
					cout << "                ※※※※※※※※※※※※※※※※※※\n\n";
					break;
				}
				else {
					if (ser2 == cur2->wi.GET_num_worker()) {
						cout << " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
						cout << " ┃            비정규직 사원번호 " << cur2->wi.GET_num_worker() << "번을 출력합니다.            ┃\n";
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃                  개     인     정     보                  ┃\n";
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃ ▷사원이름 : " << cur2->wi.GET_name_worker() << endl;
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃ ▷생년월일 : " << cur2->wi.GET_birth() << endl;
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃ ▷주    소 : " << cur2->wi.GET_address_worker() << endl;
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃ ▷이 메 일 : " << cur2->wi.GET_address_email() << endl;
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃ ▷휴대폰번호 : " << cur2->wi.GET_data_phone() << endl;
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃ ▷은행이름 : " << cur2->wi.GET_name_bank() << endl;
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃ ▷계좌번호 : " << cur2->wi.GET_bank_num() << endl;
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃                  급     여     정     보                  ┃\n";
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃ ▷월급 : " << cur2->PartTime::GET_Ppay_month() << " 원" << endl;
						cout << " ┃    ※ 시급 : " << cur2->wp.pay_hour_pay << " 원" << endl;
						cout << " ┃    ※ 일한시간 : : " << cur2->ti.GET_Time() << " 시간" << endl;
						cout << " ┃    ※ 출근일수 : " << cur2->ti.GET_Day() << " 일" << endl;
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃ ▷초과수당 : " << cur2->PartTime::GET_Ppay_overtime() << endl;
						cout << " ┃    ※ 초과근무시급(시급 x 1.5) : " << cur2->wp.pay_hour_pay * 1.5 << " 원" << endl;
						cout << " ┃    ※ 초과근무시간 : " << cur2->ti.GET_Overtime() << " 시간" << endl;
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃ ▷식비 : " << cur2->PartTime::GET_Ppay_meal() << " 원" << endl;
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃ ▷보너스 : " << cur2->wp.GET_pay_bonus() << " 원" << endl;
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃                  공     제     정     보                  ┃\n";
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃ ▷보험 : " << cur2->PartTime::GET_Pinsu() << endl;
						cout << " ┃    ※ 건강보험(월급 x 0.0306) : " << cur2->GET_Phelinsu() << " 원" << endl;
						cout << " ┃    ※ 고용보험(월급 x 0.0065) : " << cur2->GET_Pempinsu() << " 원" << endl;
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃ ▷세금 : " << cur2->PartTime::GET_PTax() << endl;
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃                  최     종     정     보                  ┃\n";
						cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
						cout << " ┃ ▷총 급여 : " << cur2->PartTime::GET_PTotal() << " 원" << endl;
						cout << " ┃ ▷총 공제 : " << cur2->PartTime::GET_PCost() << " 원" << endl;
						cout << " ┃ ▷실 수령 : " << cur2->PartTime::GET_Preal_pay() << " 원" << endl;
						cout << " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
						cout << "〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n";
						break;
					}
					cur2 = cur2->next;
				}
			}
		}
	}
};

//--------------------------------------------------------------------------------------------------------------------------------------

class Menu
{
	int sel; //변수의 기능?

public:
	void menu() {
		Master ma;
		while (sel != 3) {
			int aa = 0;
			int ba = 0;
			cout << "  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
			cout << "  ┃    ※급여관리 프로그램※   ┃\n";
			cout << "  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛                   &    &\n";
			cout << " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓                ΘωΘ야옹~\n";
			cout << " ┃                              ┃     &    &\n";
			cout << " ┃        1.   관 리 자         ┃     ΘωΘ 야옹~          &    &\n";
			cout << " ┃                              ┃                           ΘωΘ\n";
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫         ΘωΘ야옹~\n";
			cout << " ┃                              ┃        &    &           \n";
			cout << " ┃        2.   사    원         ┃        ΘωΘ\n";
			cout << " ┃                              ┃                           ΘωΘ야옹~\n";
			cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫                     ΘωΘ\n";
			cout << " ┃                              ┃\n";
			cout << " ┃        3.   종    료         ┃                  ΘωΘ야옹~\n";
			cout << " ┃                              ┃                                         ΘωΘ야옹~\n";
			cout << " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛                           ΘωΘ\n";
			cout << " ▶무엇을 하시겠습니까? >> ";
			cin >> sel;
			cout << "\n";
			switch (sel) {
			case 1:
				int pass;
				cout << "▶비밀번호를 입력하세요 : ";
				cin >> pass;
				cout << "\n";
				if (pass == 1234) {
					system("cls");
					while (aa != 6) {
						int ab = 0;
						cout << "                    ┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
						cout << "                    ┃   ◆관리자 메뉴입니다◆  ┃\n";
						cout << "                    ┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
						cout << "┏━━━━━━━━━━┳━━━━━━━━━━┳━━━━━━━━━━┳━━━━━━━━━━┳━━━━━━━━━━┳━━━━━━━━━━┓\n";
						cout << "┃ 1. 입력  ┃ 2. 출력  ┃ 3. 검색  ┃ 4. 수정  ┃ 5. 삭제  ┃ 6. 메인  ┃\n";
						cout << "┗━━━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━━━┛\n";
						cout << " ▶무엇을 하시겠습니까? >> ";
						cin >> aa;
						cout << "\n";
						switch (aa) {
						case 1: system("cls"); {
							while (ab != 3) {
								cout << "                     ┏━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
								cout << "                     ┃   ◆입력 메뉴입니다◆  ┃\n";
								cout << "                     ┗━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
								cout << "   ┏━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━┓\n";
								cout << "   ┃   1. 정규직 입력  ┃  2. 비정규직 입력 ┃    3. 이전메뉴    ┃\n";
								cout << "   ┗━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┛\n";
								cout << " ▶무엇을 하시겠습니까? >> ";
								cin >> ab;
								switch (ab) {
								case 1: system("cls");
									ma.fullinput();
									system("cls");
									cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
									cout << "                  ☆ 성공적으로 입력되었습니다! ★\n";
									cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
									break;
								case 2: system("cls");
									ma.Partinput();
									system("cls");
									cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
									cout << "                  ☆ 성공적으로 입력되었습니다! ★\n";
									cout << "                  ★☆★☆★☆★☆★☆★☆★☆★☆\n";
									break;
								case 3: system("cls");
									cout << "                   ┏━━━━━━━ Δ━━━━━━━━━ Δ━━━━━━━┓\n";
									cout << "                   (        ○    ω    ○        )\n";
									cout << "                   ┗━━━━━━ ω━━━━━━━━━━━ ω━━━━━━┛\n";
									cout << "                    §   이전메뉴로 돌아갑니다 §\n";

									break;
								default:
									system("cls");
									cout << "                      ※※※※※※※※※※※※※\n";
									cout << "                      ※  잘못된 입력입니다   ※\n";
									cout << "                      ※  다시 입력해주세요!  ※\n";
									cout << "                      ※※※※※※※※※※※※※\n\n";
								}
							}
						}break;
						case 2: system("cls");
							while (ab != 3) {
								cout << "                     ┏━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
								cout << "                     ┃   ◆출력 메뉴입니다◆  ┃\n";
								cout << "                     ┗━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
								cout << "   ┏━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━┓\n";
								cout << "   ┃   1. 정규직 출력  ┃  2. 비정규직 출력 ┃    3. 이전메뉴    ┃\n";
								cout << "   ┗━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┛\n";
								cout << " ▶무엇을 하시겠습니까? >> ";
								cin >> ab;
								switch (ab) {
								case 1: system("cls");  ma.FullOutput(); break;
								case 2: system("cls");  ma.PartOutput(); break;
								case 3: system("cls");
									cout << "                   ┏━━━━━━━ Δ━━━━━━━━━ Δ━━━━━━━┓\n";
									cout << "                   (        ○    ω    ○        )\n";
									cout << "                   ┗━━━━━━ ω━━━━━━━━━━━ ω━━━━━━┛\n";
									cout << "                    §   이전메뉴로 돌아갑니다 §\n"; break;
								default:
									system("cls");
									cout << "                      ※※※※※※※※※※※※※\n";
									cout << "                      ※  잘못된 입력입니다   ※\n";
									cout << "                      ※  다시 입력해주세요!  ※\n";
									cout << "                      ※※※※※※※※※※※※※\n\n";
								}
							}break;
						case 3:system("cls");
							while (ab != 3) {
								cout << "                     ┏━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
								cout << "                     ┃   ◆검색 메뉴입니다◆  ┃\n";
								cout << "                     ┗━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
								cout << "   ┏━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━┓\n";
								cout << "   ┃   1. 정규직 검색  ┃  2. 비정규직 검색 ┃    3. 이전메뉴    ┃\n";
								cout << "   ┗━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┛\n";
								cout << " ▶무엇을 하시겠습니까? >> ";
								cin >> ab;
								switch (ab) {
								case 1:	system("cls"); ma.Fullsearch(); break;
								case 2: system("cls");  ma.Partsearch(); break;
								case 3: system("cls");
									cout << "                   ┏━━━━━━━ Δ━━━━━━━━━ Δ━━━━━━━┓\n";
									cout << "                   (        ○    ω    ○        )\n";
									cout << "                   ┗━━━━━━ ω━━━━━━━━━━━ ω━━━━━━┛\n";
									cout << "                    §   이전메뉴로 돌아갑니다 §\n";
									break;
								default:
									system("cls");
									cout << "                      ※※※※※※※※※※※※※\n";
									cout << "                      ※  잘못된 입력입니다   ※\n";
									cout << "                      ※  다시 입력해주세요!  ※\n";
									cout << "                      ※※※※※※※※※※※※※\n\n";
								}
							}break;
						case 4: system("cls");
							while (ab != 3) {
								cout << "                     ┏━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
								cout << "                     ┃   ◆수정 메뉴입니다◆  ┃\n";
								cout << "                     ┗━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
								cout << "   ┏━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━┓\n";
								cout << "   ┃   1. 정규직 수정  ┃  2. 비정규직 수정 ┃    3. 이전메뉴    ┃\n";
								cout << "   ┗━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┛\n";
								cout << " ▶무엇을 하시겠습니까? >> ";
								cin >> ab;
								switch (ab) {
								case 1:	system("cls"); ma.Fullcorrect();
									break;
								case 2: system("cls");  ma.Partcorrect();
									break;
								case 3: system("cls");
									cout << "                   ┏━━━━━━━ Δ━━━━━━━━━ Δ━━━━━━━┓\n";
									cout << "                   (        ○    ω    ○        )\n";
									cout << "                   ┗━━━━━━ ω━━━━━━━━━━━ ω━━━━━━┛\n";
									cout << "                    §   이전메뉴로 돌아갑니다 §\n";
									break;
								default:
									system("cls");
									cout << "                      ※※※※※※※※※※※※※\n";
									cout << "                      ※  잘못된 입력입니다   ※\n";
									cout << "                      ※  다시 입력해주세요!  ※\n";
									cout << "                      ※※※※※※※※※※※※※\n\n";
								}
							}break;
						case 5: system("cls");
							while (ab != 3) {
								cout << "                     ┏━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
								cout << "                     ┃   ◆삭제 메뉴입니다◆  ┃\n";
								cout << "                     ┗━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
								cout << "   ┏━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━┓\n";
								cout << "   ┃   1. 정규직 삭제  ┃  2. 비정규직 삭제 ┃    3. 이전메뉴    ┃\n";
								cout << "   ┗━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┛\n";
								cout << " ▶무엇을 하시겠습니까? >> ";
								cin >> ab;
								switch (ab) {
								case 1:	system("cls"); ma.Fulldele(); break;
								case 2: system("cls");  ma.Partdele(); break;
								case 3: system("cls");
									cout << "                   ┏━━━━━━━ Δ━━━━━━━━━ Δ━━━━━━━┓\n";
									cout << "                   (        ○    ω    ○        )\n";
									cout << "                   ┗━━━━━━ ω━━━━━━━━━━━ ω━━━━━━┛\n";
									cout << "                    §   이전메뉴로 돌아갑니다 §\n";
									break;
								default:
									system("cls");
									cout << "                      ※※※※※※※※※※※※※\n";
									cout << "                      ※  잘못된 입력입니다   ※\n";
									cout << "                      ※  다시 입력해주세요!  ※\n";
									cout << "                      ※※※※※※※※※※※※※\n\n";
								}
							}break;
						case 6: system("cls");
							cout << "  ┏━━━━━━━ Δ━━━━━━━━━ Δ━━━━━━━┓\n";
							cout << "  (        ○    ω    ○        )\n";
							cout << "  ┗━━━━━━ ω━━━━━━━━━━━ ω━━━━━━┛\n";
							cout << "   §   메인메뉴로 돌아갑니다 §\n"; break;
						default:
							system("cls");
							cout << "                      ※※※※※※※※※※※※※\n";
							cout << "                      ※  잘못된 입력입니다   ※\n";
							cout << "                      ※  다시 입력해주세요!  ※\n";
							cout << "                      ※※※※※※※※※※※※※\n\n";
						}

					}

				}
				else {
					system("cls");
					cout << "※※※※※※※※※※※※※※※※※※\n";
					cout << "※      비밀번호가 틀렸습니다     ※\n";
					cout << "※       다시 입력해 주세요!      ※\n";
					cout << "※※※※※※※※※※※※※※※※※※\n\n";
				}
				break;
			case 2: system("cls");
				while (aa != 2) {
					int ac = 0;
					cout << "    ┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
					cout << "    ┃   ◆사  원 메뉴입니다◆  ┃\n";
					cout << "    ┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
					cout << "┏━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━┓\n";
					cout << "┃   1. 정보보기   ┃     2. 메인     ┃\n";
					cout << "┗━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━┛\n";
					cout << " ▶무엇을 하시겠습니까? >> ";
					cin >> aa;
					cout << "\n";
					switch (aa) {
					case 1:system("cls");
						while (ac != 3) {

							cout << "                  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
							cout << "                  ┃    ◆정보보기 메뉴입니다◆    ┃\n";
							cout << "                  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
							cout << "   ┏━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━┓\n";
							cout << "   ┃     1. 정규직     ┃     2. 비정규직    ┃    3. 이전메뉴    ┃\n";
							cout << "   ┗━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┛\n";
							cout << " ▶고용형태를 선택하세요 >> ";
							cin >> ac;
							cout << "\n";
							switch (ac)
							{
							case 1:  system("cls"); ma.Fullsearch(); break;
							case 2:  system("cls"); ma.Partsearch(); break;
							case 3: system("cls");
								cout << "   ┏━━━━━━━ Δ━━━━━━━━━ Δ━━━━━━━┓\n";
								cout << "   (        ○    ω    ○        )\n";
								cout << "   ┗━━━━━━ ω━━━━━━━━━━━ ω━━━━━━┛\n";
								cout << "    §  이전메뉴로 돌아갑니다  §\n"; break;
							default:
								system("cls");
								cout << "                      ※※※※※※※※※※※※※\n";
								cout << "                      ※  잘못된 입력입니다   ※\n";
								cout << "                      ※  다시 입력해주세요!  ※\n";
								cout << "                      ※※※※※※※※※※※※※\n\n";
							}
						}
						break;
					case 2:
						system("cls");
						cout << "  ┏━━━━━━━ Δ━━━━━━━━━ Δ━━━━━━━┓\n";
						cout << "  (        ○    ω    ○        )\n";
						cout << "  ┗━━━━━━ ω━━━━━━━━━━━ ω━━━━━━┛\n";
						cout << "   §   메인메뉴로 돌아갑니다 §\n"; break;
					default:
						system("cls");
						cout << "     ※※※※※※※※※※※※※\n";
						cout << "     ※  잘못된 입력입니다   ※\n";
						cout << "     ※  다시 입력해주세요!  ※\n";
						cout << "     ※※※※※※※※※※※※※\n\n";
					}
				}
				break;
			case 3:
				system("cls");
				for (int i = 0; i < 25; i++) {
					cout << "\n\n\n\n\n\n";
					cout << "                 ■                                □\n";
					cout << "                   □■□■□■□■□■□■□■□■\n";
					cout << "                   ■                            □\n";
					cout << "                   □ 관리프로그램을 종료합니다. ■\n";
					cout << "                   ■                            □\n";
					cout << "                   □■□■□■□■□■□■□■□■\n";
					cout << "                 □                                □\n";
					Sleep(100);
					system("cls");
					cout << "\n\n\n\n\n\n";
					cout << "                 □                                ■\n";
					cout << "                   ■□■□■□■□■□■□■□■□\n";
					cout << "                   □                            ■\n";
					cout << "                   ■ 관리프로그램을 종료합니다. □\n";
					cout << "                   □                            ■\n";
					cout << "                   ■□■□■□■□■□■□■□■□\n";
					cout << "                 □                                □\n\n";
					Sleep(100);
					system("cls");
					cout << "\n\n\n\n\n\n";
					cout << "                 □                                □\n";
					cout << "                   □■□■□■□■□■□■□■□■\n";
					cout << "                   ■                            □\n";
					cout << "                   □ 관리프로그램을 종료합니다. ■\n";
					cout << "                   ■                            □\n";
					cout << "                   □■□■□■□■□■□■□■□■\n";
					cout << "                 □                                ■\n\n";
					Sleep(100);
					system("cls");
					cout << "\n\n\n\n\n\n";
					cout << "                 □                                □\n";
					cout << "                   ■□■□■□■□■□■□■□■□\n";
					cout << "                   □                            ■\n";
					cout << "                   ■ 관리프로그램을 종료합니다. □\n";
					cout << "                   □                            ■\n";
					cout << "                   ■□■□■□■□■□■□■□■□\n";
					cout << "                 ■                                □\n\n";
					Sleep(100);
					system("cls");

				}
				break;
			default:
				system("cls");
				cout << "    ※※※※※※※※※※※※※\n";
				cout << "    ※  잘못된 입력입니다   ※\n";
				cout << "    ※  다시 입력해주세요!  ※\n";
				cout << "    ※※※※※※※※※※※※※\n\n";
			}
		}
	}
};
//------------------------------------------------------------------------------------------------------------------
void main() {
	//List a;

	cout << "          \n로딩중....\n";
	for (int i = 0; i < 1; i++) {

		cout << "□□□□□□□□□□ (0%)" << flush;

		Sleep(100);
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b■□□□□□□□□□ (10%)" << flush;

		Sleep(100);
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b■■□□□□□□□□ (20%)" << flush;

		Sleep(100);
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b■■■□□□□□□□ (30%)" << flush;

		Sleep(100);
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b■■■■□□□□□□ (40%)" << flush;

		Sleep(100);
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b■■■■■□□□□□ (50%)" << flush;

		Sleep(100);
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b■■■■■■□□□□ (60%)" << flush;

		Sleep(100);
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b■■■■■■■□□□ (70%)" << flush;

		Sleep(100);
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b■■■■■■■■□□ (80%)" << flush;

		Sleep(100);
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b■■■■■■■■■□ (90%)" << flush;

		Sleep(100);
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b■■■■■■■■■■ (100%)\n" << flush;
		cout << "로딩완료!";
		break;
	}
	Sleep(1000);

	system("cls");
	Menu sele;
	sele.menu();
}
