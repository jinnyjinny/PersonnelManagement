#include<iostream> //cout, cin,endl 蛔 晦獄 殮轎溘 л熱蒂 んли ④渦だ橾檜棻.
#include<string> //僥濠翮擊 籀葬ж朝 string 贗楚蝶陛 んли ④渦だ橾檜棻. 
#include<iomanip> //flush л熱蒂 んли ④渦だ橾檜棻.
#include <Windows.h> //Sleep л熱蒂 んли ④渦だ橾檜棻.
using namespace std; //ル遽 啻歜蝶む檜蝶蒂 餌辨


class Time_Oper //time, year, overtime, day婁 偽擎 衛除 だ塭詭攪高擊 賅嬴菩 贗楚蝶
{
	int time;
	int year;
	int overtime;
	int day;
public: // 晦奩贗楚蝶檣 Time_Oper縑憮 噙檜朝 public詹幗滲熱蒂 蟾晦�倆挬�. 
	void SET_Day(int day) { // SET_Day曖 晦棟擊 ж朝 詭模萄蒂 薑曖и棻. this->day曖 曖嘐: day滲熱蒂 棻艇 贗楚蝶縑憮紫 噙晦嬪п?  
		this->day = day;
	}
	int GET_Day() { return day; } //return高曖 曖嘐朝?-> 高擊 奩�納挬�. 啗骯脹 day塭朝 高擊 乾堅 ��轎脹 睡碟戲煎 棻衛 給嬴馬
	void SET_Time(int time) { this->time = time; }
	int GET_Time() { return time; }
	void SET_Year(int year) { this->year = year; }
	int GET_Year() { return year; }
	void SET_Overtime(int overtime) { this->overtime = overtime; }
	int GET_Overtime() { return overtime; }
};
class Worker_Pay_Oper : protected Time_Oper { 
	//錯晝, 橾晝, 衛晝, 撿斬熱渡, 衝綠, 爾傘蝶 滲熱 賅擠 贗楚蝶
public:
	unsigned int pay_month;      //錯晝
	unsigned int pay_year;      //翱瑰
	unsigned int pay_day;        //橾渡
	unsigned int pay_hour;   //ж瑞橾и衛除
	unsigned int pay_hour_pay;      //衛晝
	unsigned int pay_overtime;   //撿斬熱渡
	unsigned int pay_meal;      //衝綠
	unsigned int pay_bonus;      //爾傘蝶
	int pension;      //翱旎
	int insurance;     //爾я
	int tax;         //模菜撮
	unsigned int real_pay;      //褒熱滄擋

	Worker_Pay_Oper() { //pay_hour_pay曖 蟾晦�� 高擊 雖薑. 檜諼曖 匙菟擎 壽縑 詭模萄縑憮 蟾晦��.
		/*	pay_month = 0;
		pay_year = GET_pay_month() * 12;
		pay_day = 0;*/
		pay_hour_pay = 8350; //2019 5錯 ⑷營 譆盪衛晝奩艙
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
//餌錳 薑爾 偌羹 賅擠
class Worker_Info
{

	string name_worker;    //餌錳 檜葷
	string name_bank;      //擎ч 檜葷
	string address_worker;   //餌錳 輿模
	string address_email;   //檜詭橾

	int num_worker;   //餌錳廓��   0000
	string birth;      //儅喇錯橾   19990101
	string data_phone;   //翱塊籀      010-5431-9587
	string bank_num;   //啗謝廓��   

	typedef enum { 憲夥儅, 綠薑敘霜, 薑敘霜, }rank_worker; //typedef: sturct 酈錶萄 橈檜 л熱曖 滌蘆擊 rank_worker煎 薑曖    

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
	Worker_Pay_Oper wp; //錯晝, 橾晝, 衛晝, 撿斬熱渡, 衝綠, 爾傘蝶 偌羹 賅擠 贗楚蝶 -> wp煎 滲熱貲 摹樹
	Worker_Info wi; //餌錳 薑爾 偌羹 賅擠 贗楚蝶 -> wi煎 滲熱貲 摹樹
	Time_Oper ti; //time, year, overtime, day 偌羹 賅擠 贗楚蝶 -> ti煎 滲熱貲 摹樹
};

class FullTime : public List {
public:
	FullTime* next; // 棻擠喻萄
	FullTime* head; //head 高 ん檣攪 雖薑
	FullTime()
	{
		next = head = NULL;
	}

	int GET_pay_month() { return ti.GET_Day() * ti.GET_Time() * wp.pay_hour_pay; } //錯晝
	int GET_pay_year() { return GET_pay_month() * 12; }//翱瑰
	int GET_pay_overtime() { return ti.GET_Overtime() * (wp.pay_hour_pay * 1.5); }//蟾婁熱渡
	int GET_pay_meal() { return ti.GET_Day() * 6000; }//衝綠
	int GET_pension() { return (int)GET_pay_month() * 0.045; } //翱旎
	int GET_insu() { return GET_helinsu() + GET_empinsu(); }//識爾я
	int GET_helinsu() { return GET_pay_month() * 0.0323; } //勒鬼爾я
	int GET_empinsu() { return GET_pay_month() * 0.0065; } //堅辨爾я
	int GET_Tax() { //撮旎: 模菜碟嬪滌煎 棻腦啪 啗骯и棻
		if (GET_pay_year() < 12000000) { //1200嘐虜 模菜碟嬪
			wp.SET_Tax((int)(GET_pay_year() * 0.06) / 12); //唸婁高擎 int 高戲煎 ⑽滲��
		}
		else if (GET_pay_year() > 12000000 && GET_pay_year() < 46000000) { //1200虜錳蟾婁 4600虜錳嘐虜 模菜碟嬪
			wp.SET_Tax((int)((GET_pay_year() * 0.15) - 1080000) / 12);
		}
		else if (GET_pay_year() > 46000000 && GET_pay_year() < 88000000) { //4600虜錳蟾婁 8800虜錳嘐虜 模菜碟嬪
			wp.SET_Tax((int)((GET_pay_year() * 0.24) - 5220000) / 12);
		}
		else if (GET_pay_year() > 88000000 && GET_pay_year() < 150000000) { //8800虜錳蟾婁 1橘5000虜錳嘐虜 模菜碟嬪
			wp.SET_Tax((int)((GET_pay_year() * 0.35) - 14900000) / 12);
		}
		else if (GET_pay_year() > 150000000) { //1橘5000虜錳蟾婁 模菜碟嬪
			wp.SET_Tax((int)((GET_pay_year() * 0.38) - 19400000) / 12);
		}return wp.GET_Tax();
	}
	int GET_Total() { return  GET_pay_month() + GET_pay_overtime() + GET_pay_meal(); }
	int GET_Cost() { return GET_pension() + GET_insu() + GET_Tax(); }
	int GET_real_pay() { return GET_pay_month() + GET_pay_overtime() + GET_pay_meal() - GET_pension() - GET_insu() - GET_Tax(); } //褒晝罹


};
class PartTime : public List {
public:
	PartTime* next; // 棻擠喻萄
	PartTime* head;
	PartTime()
	{
		next = head = NULL;
	}

	int GET_Ppay_month() { return (ti.GET_Day()) * ti.GET_Time() * wp.pay_hour_pay; }//錯晝
	int GET_Ppay_year() { return GET_Ppay_month() * 12; }//翱瑰
	int GET_Ppay_overtime() { return ti.GET_Overtime() * (wp.pay_hour_pay * 1.5); }//蟾婁熱渡
	int GET_Ppay_meal() { return ti.GET_Day() * 6000; }//衝綠
	int GET_Pinsu() { return GET_Phelinsu() + GET_Pempinsu(); }//識爾я
	int GET_Phelinsu() { return GET_Ppay_month() * 0.0323; } //勒鬼爾я
	int GET_Pempinsu() { return GET_Ppay_month() * 0.0065; } //堅辨爾я
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
	int GET_PCost() { return  GET_Pinsu() + GET_PTax(); }//識奢薯
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
	FullTime* head, * del, * cur, * new1; //fulltime縑 翱唸腎朝 ん檣攪 滲熱高 薑曖
	PartTime* head2, * del2, * cur2, * new2;
	Master() { //Master 儅撩濠摹樹
		count1 = 0;
		count2 = 0;
		head = del = cur = new1 = NULL; //ん檣攪 高 蟾晦��. 
		head2 = del2 = cur2 = new2 = NULL;
	}
	void fullinput() {
		count1 += 1; //餌錳廓�ㄧ� 濠翕戲煎 睡罹ж晦 嬪п 隸馬衝擊 噪
		if (head == NULL) {
			FullTime* new1 = new FullTime(); // 億煎遴 餌錳曖 薑爾蒂 蹺晦衛酈晦 嬪п 億煎遴 喻萄蒂 儅撩и棻
			head = new1; //萄蛤橫 儅撩喻萄蒂 陛腦酈朝 headん檣攪蒂 雖薑и棻.
			new1->wi.SET_num_worker(count1); //count1縑 п渡腎朝 等檜攪 高擊 殮溘и棻.
			cout << " 旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n";
			cout << " 早             薑敘霜 餌錳廓�� " << new1->wi.GET_num_worker() << "廓擊 殮溘м棲棻.             早\n";
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早               餌錳曖 偃檣薑爾蒂 殮溘м棲棻.               早\n";
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ餌錳檜葷擊 殮溘ж撮蹂 : ";
			cin >> n;
			new1->wi.SET_name_worker(n);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ儅喇錯橾擊 殮溘ж撮蹂 ex. 19930222 : ";
			cin >> n;
			new1->wi.SET_birth(n);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ輿模蒂 殮溘ж撮蹂 : ";
			cin >> n;
			new1->wi.SET_address_worker(n);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ檜詭橾擊 殮溘ж撮蹂 : ";
			cin >> n;
			new1->wi.SET_address_email(n);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ�瑒踰齈醽ㄧ� 殮溘ж撮蹂 : ";
			cin >> n;
			new1->wi.SET_data_phone(n);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ擎ч檜葷擊 殮溘ж撮蹂 : ";
			cin >> n;
			new1->wi.SET_name_bank(n);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ啗謝廓�ㄧ� 殮溘ж撮蹂 : ";
			cin >> n;
			new1->wi.SET_bank_num(n);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早               餌錳曖 斬煎橾熱蒂 殮溘м棲棻.               早\n";
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ斬煎衛除擊 殮溘ж撮蹂 : ";
			cin >> m;
			new1->ti.SET_Time(m);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ斬煎橾熱蒂 殮溘ж撮蹂 : ";
			cin >> m;
			new1->ti.SET_Day(m);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ蟾婁 斬煎衛除擊 殮溘ж撮蹂 : ";
			cin >> m;
			new1->ti.SET_Overtime(m);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ爾傘蝶蒂 殮溘ж撮蹂 : ";
			cin >> m;
			new1->wp.SET_pay_bonus(m);
			cout << " 曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n";
			Sleep(500);
		}
		else { //head !=NULL 檣 唳辦 -> 餌錳廓�ㄟ� 1檜 嬴棋唳辦. cur =head 檜晦 陽僥.
			//殮溘脹啪 氈擊 �� 殮溘ж朝 薑爾
			FullTime* new1 = new FullTime(); //傳 棻衛 喻萄 儅撩
			new1->wi.SET_num_worker(count1); //new1.л熱 (л熱��轎衝婁 嶸餌л)
			cout << " 旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n";
			cout << " 早             薑敘霜 餌錳廓�� " << new1->wi.GET_num_worker() << "廓擊 殮溘м棲棻.             早\n";
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早               餌錳曖 偃檣薑爾蒂 殮溘м棲棻.               早\n";
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ餌錳檜葷擊 殮溘ж撮蹂 : ";
			cin >> n;
			new1->wi.SET_name_worker(n);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ儅喇錯橾擊 殮溘ж撮蹂 ex. 19930222 : ";
			cin >> n;
			new1->wi.SET_birth(n);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ輿模蒂 殮溘ж撮蹂 : ";
			cin >> n;
			new1->wi.SET_address_worker(n);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ檜詭橾擊 殮溘ж撮蹂 : ";
			cin >> n;
			new1->wi.SET_address_email(n);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ�瑒踰齈醽ㄧ� 殮溘ж撮蹂 : ";
			cin >> n;
			new1->wi.SET_data_phone(n);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ擎ч檜葷擊 殮溘ж撮蹂 : ";
			cin >> n;
			new1->wi.SET_name_bank(n);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ啗謝廓�ㄧ� 殮溘ж撮蹂 : ";
			cin >> n;
			new1->wi.SET_bank_num(n);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早               餌錳曖 斬煎橾熱蒂 殮溘м棲棻.               早\n";
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ斬煎衛除擊 殮溘ж撮蹂 : ";
			cin >> m;
			new1->ti.SET_Time(m);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ斬煎橾熱蒂 殮溘ж撮蹂 : ";
			cin >> m;
			new1->ti.SET_Day(m);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ蟾婁 斬煎衛除擊 殮溘ж撮蹂 : ";
			cin >> m;
			new1->ti.SET_Overtime(m);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ爾傘蝶蒂 殮溘ж撮蹂 : ";
			cin >> m;
			new1->wp.SET_pay_bonus(m);
			cout << " 曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n";
			Sleep(500);
			cur = head; //cur檜塭朝 歜曖曖ん檣攪蒂 虜菟橫 場堅 斜 head高擊 衡啖遽棻
			while (cur->next != NULL) { //棻擠 喻萄 -> 殮溘й 喻萄 陛腦酈紫煙 ж朝 掘僥
				cur = cur->next; //棻擠 喻萄 檜翕
			}
			new1->next = NULL; //陛腦儷戲賊 檜 掘僥縑憮 綠辦堅 棻艇 喻萄煎 剩橫除棻
			cur->next = new1; //⑷營 ん檣攪 高擊 棻擠 喻萄煎 陛腦酈啪 и棻. 

		}
	}
	void Partinput() {
		count2 += 1;

		if (head2 == NULL) {
			PartTime* new2 = new PartTime();
			head2 = new2;
			new2->wi.SET_num_worker(count2);
			cout << " 旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n";
			cout << " 早            綠薑敘霜 餌錳廓�� " << new2->wi.GET_num_worker() << "廓擊 殮溘м棲棻.            早\n";
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早               餌錳曖 偃檣薑爾蒂 殮溘м棲棻.               早\n";
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ餌錳檜葷擊 殮溘ж撮蹂 : ";
			cin >> n;
			new2->wi.SET_name_worker(n);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ儅喇錯橾擊 殮溘ж撮蹂 ex. 19930222 : ";
			cin >> n;
			new2->wi.SET_birth(n);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ輿模蒂 殮溘ж撮蹂 : ";
			cin >> n;
			new2->wi.SET_address_worker(n);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ檜詭橾擊 殮溘ж撮蹂 : ";
			cin >> n;
			new2->wi.SET_address_email(n);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ�瑒踰齈醽ㄧ� 殮溘ж撮蹂 : ";
			cin >> n;
			new2->wi.SET_data_phone(n);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ擎ч檜葷擊 殮溘ж撮蹂 : ";
			cin >> n;
			new2->wi.SET_name_bank(n);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ啗謝廓�ㄧ� 殮溘ж撮蹂 : ";
			cin >> n;
			new2->wi.SET_bank_num(n);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早               餌錳曖 斬煎橾熱蒂 殮溘м棲棻.               早\n";
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ斬煎衛除擊 殮溘ж撮蹂 : ";
			cin >> m;
			new2->ti.SET_Time(m);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ斬煎橾熱蒂 殮溘ж撮蹂 : ";
			cin >> m;
			new2->ti.SET_Day(m);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ蟾婁 斬煎衛除擊 殮溘ж撮蹂 : ";
			cin >> m;
			new2->ti.SET_Overtime(m);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ爾傘蝶蒂 殮溘ж撮蹂 : ";
			cin >> m;
			new2->wp.SET_pay_bonus(m);
			cout << " 曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n";
			Sleep(500);

		}
		else {

			PartTime* new2 = new PartTime();
			new2->wi.SET_num_worker(count2);
			cout << " 旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n";
			cout << " 早             綠薑敘霜 餌錳廓�� " << new2->wi.GET_num_worker() << "廓擊 殮溘м棲棻.           早\n";
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早               餌錳曖 偃檣薑爾蒂 殮溘м棲棻.               早\n";
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ餌錳檜葷擊 殮溘ж撮蹂 : ";
			cin >> n;
			new2->wi.SET_name_worker(n);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ儅喇錯橾擊 殮溘ж撮蹂 ex. 19930222 : ";
			cin >> n;
			new2->wi.SET_birth(n);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ輿模蒂 殮溘ж撮蹂 : ";
			cin >> n;
			new2->wi.SET_address_worker(n);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ檜詭橾擊 殮溘ж撮蹂 : ";
			cin >> n;
			new2->wi.SET_address_email(n);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ�瑒踰齈醽ㄧ� 殮溘ж撮蹂 : ";
			cin >> n;
			new2->wi.SET_data_phone(n);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ擎ч檜葷擊 殮溘ж撮蹂 : ";
			cin >> n;
			new2->wi.SET_name_bank(n);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ啗謝廓�ㄧ� 殮溘ж撮蹂 : ";
			cin >> n;
			new2->wi.SET_bank_num(n);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早               餌錳曖 斬煎橾熱蒂 殮溘м棲棻.               早\n";
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ斬煎衛除擊 殮溘ж撮蹂 : ";
			cin >> m;
			new2->ti.SET_Time(m);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ斬煎橾熱蒂 殮溘ж撮蹂 : ";
			cin >> m;
			new2->ti.SET_Day(m);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ蟾婁 斬煎衛除擊 殮溘ж撮蹂 : ";
			cin >> m;
			new2->ti.SET_Overtime(m);
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
			cout << " 早 Ⅰ爾傘蝶蒂 殮溘ж撮蹂 : ";
			cin >> m;
			new2->wp.SET_pay_bonus(m);
			cout << " 曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n";
			Sleep(500);
			cur2 = head2;
			while (cur2->next != NULL) {
				cur2 = cur2->next; //棻擠 喻萄 檜翕
			}
			new2->next = cur2->next;
			cur2->next = new2;
		}

	}
	//---------------------------------------------------------------------------------------------------------------------------------------------------
	void FullOutput()
	{
		if (head == NULL) { //殮溘脹啪 ж釭紫 橈擊 唳辦縑 檜勘 轎溘ж堅
			cout << "                ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n";
			cout << "                ≦    薑爾陛 襄營ж雖 彊蝗棲棻!   ≦\n";
			cout << "                ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n\n";
		}
		else { //殮溘脹啪 氈擊 唳辦縑 檜勘 轎溘и棻
			cur = head; //head高 犒餌л
			while (cur != NULL) //虜擒 5廓梱雖 殮溘腎橫氈戲賊 1~5梱雖 牖離瞳戲煎 瞪羹 轎溘(奩犒僥) cur !=NULL  <- 等檜攪陛 氈戲賊 奩犒瞳戲煎 等檜渦蒂 轎溘ж堅 橈戲賊 部陴
			{
				cout << " 旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n";
				cout << " 早             薑敘霜 餌錳廓�� " << cur->wi.GET_num_worker() << "廓擊 轎溘м棲棻.             早\n";
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早                  偃     檣     薑     爾                  早\n";
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早 Ⅰ餌錳檜葷 : " << cur->wi.GET_name_worker() << endl;
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早 Ⅰ儅喇錯橾 : " << cur->wi.GET_birth() << endl;
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早 Ⅰ輿    模 : " << cur->wi.GET_address_worker() << endl;
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早 Ⅰ檜 詭 橾 : " << cur->wi.GET_address_email() << endl;
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早 Ⅰ�瑒踰齈醽� : " << cur->wi.GET_data_phone() << endl;
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早 Ⅰ擎ч檜葷 : " << cur->wi.GET_name_bank() << endl;
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早 Ⅰ啗謝廓�� : " << cur->wi.GET_bank_num() << endl;
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早                  晝     罹     薑     爾                  早\n";
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早 Ⅰ錯晝 : " << cur->FullTime::GET_pay_month() << " 錳" << endl;
				cout << " 早    ≦ 衛晝 : " << cur->wp.pay_hour_pay << " 錳" << endl;
				cout << " 早    ≦ 橾и衛除 : : " << cur->ti.GET_Time() << " 衛除" << endl;
				cout << " 早    ≦ 轎斬橾熱 : " << cur->ti.GET_Day() << " 橾" << endl;
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早 Ⅰ蟾婁熱渡 : " << cur->FullTime::GET_pay_overtime() << " 錳" << endl;
				cout << " 早    ≦ 蟾婁斬鼠衛晝(衛晝 x 1.5) : " << cur->wp.pay_hour_pay * 1.5 << " 錳" << endl;
				cout << " 早    ≦ 蟾婁斬鼠衛除 : " << cur->ti.GET_Overtime() << " 衛除" << endl;
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早 Ⅰ衝綠(轎斬橾熱 * 6000) : " << cur->FullTime::GET_pay_meal() << " 錳" << endl;
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早 Ⅰ爾傘蝶 : " << cur->wp.GET_pay_bonus() << " 錳" << endl;
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早                  奢     薯     薑     爾                  早\n";
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早 Ⅰ翱旎(錯晝 x 0.045) : " << cur->FullTime::GET_pension() << " 錳" << endl;
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早 Ⅰ爾я : " << cur->FullTime::GET_insu() << " 錳" << endl;
				cout << " 早    ≦ 勒鬼爾я(錯晝 x 0.0306) : " << cur->GET_helinsu() << " 錳" << endl;
				cout << " 早    ≦ 堅辨爾я(錯晝 x 0.0065) : " << cur->GET_empinsu() << " 錳" << endl;
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早 Ⅰ撮旎 : " << cur->FullTime::GET_Tax() << " 錳" << endl;
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早                  譆     謙     薑     爾                  早\n";
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早 Ⅰ識 晝罹 : " << cur->FullTime::GET_Total() << " 錳" << endl;
				cout << " 早 Ⅰ識 奢薯 : " << cur->FullTime::GET_Cost() << " 錳" << endl;
				cout << " 早 Ⅰ褒 熱滄 : " << cur->FullTime::GET_real_pay() << " 錳" << endl;
				cout << " 曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n";
				cout << "㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑\n";
				cur = cur->next;
			}
		}
	}
	void PartOutput()
	{
		if (head2 == NULL) {
			cout << "                ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n";
			cout << "                ≦    薑爾陛 襄營ж雖 彊蝗棲棻!   ≦\n";
			cout << "                ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n\n";
		}
		else {
			cur2 = head2;
			while (cur2 != NULL)
			{
				cout << " 旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n";
				cout << " 早             綠薑敘霜 餌錳廓�� " << cur2->wi.GET_num_worker() << "廓擊 轎溘м棲棻.           早\n";
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早                  偃     檣     薑     爾                  早\n";
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早 Ⅰ餌錳檜葷 : " << cur2->wi.GET_name_worker() << endl;
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早 Ⅰ儅喇錯橾 : " << cur2->wi.GET_birth() << endl;
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早 Ⅰ輿    模 : " << cur2->wi.GET_address_worker() << endl;
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早 Ⅰ檜 詭 橾 : " << cur2->wi.GET_address_email() << endl;
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早 Ⅰ�瑒踰齈醽� : " << cur2->wi.GET_data_phone() << endl;
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早 Ⅰ擎ч檜葷 : " << cur2->wi.GET_name_bank() << endl;
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早 Ⅰ啗謝廓�� : " << cur2->wi.GET_bank_num() << endl;
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早                  晝     罹     薑     爾                  早\n";
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早 Ⅰ錯晝 : " << cur2->PartTime::GET_Ppay_month() << " 錳" << endl;
				cout << " 早    ≦ 衛晝 : " << cur2->wp.pay_hour_pay << " 錳" << endl;
				cout << " 早    ≦ 斬煎衛除 : : " << cur2->ti.GET_Time() << " 衛除" << endl;
				cout << " 早    ≦ 轎斬橾熱 : " << cur2->ti.GET_Day() << " 橾" << endl;
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早 Ⅰ蟾婁熱渡 : " << cur2->PartTime::GET_Ppay_overtime() << " 錳" << endl;
				cout << " 早    ≦ 蟾婁斬鼠衛晝(衛晝 x 1.5) : " << cur2->wp.pay_hour_pay * 1.5 << " 錳" << endl;
				cout << " 早    ≦ 蟾婁斬鼠衛除 : " << cur2->ti.GET_Overtime() << " 衛除" << endl;
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早 Ⅰ衝綠(轎斬橾熱 * 6000) : " << cur2->PartTime::GET_Ppay_meal() << " 錳" << endl;
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早 Ⅰ爾傘蝶 : " << cur2->wp.GET_pay_bonus() << " 錳" << endl;
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早                  奢     薯     薑     爾                  早\n";
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早 Ⅰ爾я : " << cur2->PartTime::GET_Pinsu() << " 錳" << endl;
				cout << " 早    ≦ 勒鬼爾я(錯晝 x 0.0306) : " << cur2->GET_Phelinsu() << " 錳" << endl;
				cout << " 早    ≦ 堅辨爾я(錯晝 x 0.0065) : " << cur2->GET_Pempinsu() << " 錳" << endl;
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早 Ⅰ撮旎 : " << cur2->PartTime::GET_PTax() << " 錳" << endl;
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早                  譆     謙     薑     爾                  早\n";
				cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
				cout << " 早 Ⅰ識 晝罹 : " << cur2->PartTime::GET_PTotal() << " 錳" << endl;
				cout << " 早 Ⅰ識 奢薯 : " << cur2->PartTime::GET_PCost() << " 錳" << endl;
				cout << " 早 Ⅰ褒 熱滄 : " << cur2->PartTime::GET_Preal_pay() << " 錳" << endl;
				cout << " 曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n";
				cout << "㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑\n";
				cur2 = cur2->next;
			}
		}
	}
	//-------------------------------------------------------------------------------------------------------------------------------------------
	void Fulldele() {
		int comp;
		//cur = head->next; 
		if (head == NULL) {
			cout << "                ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n";
			cout << "                ≦    薑爾陛 襄營ж雖 彊蝗棲棻!   ≦\n";
			cout << "                ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n\n";
		}
		else {

			cout << " Ⅱ餉薯 й 餌錳廓�ㄧ� 殮溘ж撮蹂 : ";
			cin >> comp;
			cur = head;
			while (1) {
				if (cur == NULL) {
					system("cls");
					cout << "                ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n";
					cout << "                ≦    薑爾陛 襄營ж雖 彊蝗棲棻!   ≦\n";
					cout << "                ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n\n";
					break;
				}
				else {
					if (comp == cur->wi.GET_num_worker() && cur == head) {
						head = head->next;
						delete(cur);
						system("cls");
						cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
						cout << "                  ≧ 撩奢瞳戲煎 餉薯腎歷蝗棲棻! ≠\n";
						cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
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
						cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
						cout << "                  ≧ 撩奢瞳戲煎 餉薯腎歷蝗棲棻! ≠\n";
						cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
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
						cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
						cout << "                  ≧ 撩奢瞳戲煎 餉薯腎歷蝗棲棻! ≠\n";
						cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
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
			cout << "                ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n";
			cout << "                ≦    薑爾陛 襄營ж雖 彊蝗棲棻!   ≦\n";
			cout << "                ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n\n";
		}
		else {

			cout << " Ⅱ餉薯 й 餌錳廓�ㄧ� 殮溘ж撮蹂 : ";
			cin >> comp2;
			cur2 = head2;
			while (1) {
				if (cur2 == NULL) {
					system("cls");
					cout << "                ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n";
					cout << "                ≦    薑爾陛 襄營ж雖 彊蝗棲棻!   ≦\n";
					cout << "                ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n\n";
					break;
				}
				else {
					if (comp2 == cur2->wi.GET_num_worker() && cur2 == head2) {
						head2 = head2->next;
						delete(cur2);
						system("cls");
						cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
						cout << "                  ≧ 撩奢瞳戲煎 餉薯腎歷蝗棲棻! ≠\n";
						cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
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
						cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
						cout << "                  ≧ 撩奢瞳戲煎 餉薯腎歷蝗棲棻! ≠\n";
						cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
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
						cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
						cout << "                  ≧ 撩奢瞳戲煎 餉薯腎歷蝗棲棻! ≠\n";
						cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
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
			cout << "                ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n";
			cout << "                ≦    薑爾陛 襄營ж雖 彊蝗棲棻!   ≦\n";
			cout << "                ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n\n";
		}
		else {
			cout << "\n";
			cout << " Ⅱ熱薑 й 餌錳廓�ㄧ� 殮溘ж撮蹂 : ";
			cin >> cor1;
			system("cls");
			cur = head;
			while (1) {
				if (cur == NULL) {
					system("cls");
					cout << "                ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n";
					cout << "                ≦    薑爾陛 襄營ж雖 彊蝗棲棻!   ≦\n";
					cout << "                ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n\n";
					break;
				}
				else {
					if (cor1 == cur->wi.GET_num_worker()) {
						cout << " 十十十十十十十十十十十十十十十十十十十\n";
						cout << " 十       薑敘霜 熱薑詭景殮棲棻.     十\n";
						cout << " 十    熱薑й 薑爾蒂 殮溘п輿撮蹂!   十\n";
						cout << " 十十十十十十十十十十十十十十十十十十十\n";
						cout << " 十         偃   檣   薑   爾        十\n";
						cout << " 十㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑十\n";
						cout << " 十≦餌錳廓�ㄐ� " << cur->wi.GET_num_worker() << endl;
						cout << " 十Ⅰ餌錳檜葷８ : " << cur->wi.GET_name_worker() << endl;
						cout << " 十Ⅰ儅喇錯橾８ : " << cur->wi.GET_birth() << endl;
						cout << " 十Ⅰ輿    模８ : " << cur->wi.GET_address_worker() << endl;
						cout << " 十Ⅰ檜 詭 橾８ : " << cur->wi.GET_address_email() << endl;
						cout << " 十Ⅰ�瑒踰齈醽ㄑ� : " << cur->wi.GET_data_phone() << endl;
						cout << " 十Ⅰ擎ч檜葷８ : " << cur->wi.GET_name_bank() << endl;
						cout << " 十Ⅰ啗謝廓�ㄑ�: " << cur->wi.GET_bank_num() << endl;
						cout << " 十十十十十十十十十十十十十十十十十十十\n";
						cout << " 十         晝   罹   薑   爾        十\n";
						cout << " 十㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑十\n";
						cout << " 十Ⅰ斬煎衛除８ : " << cur->ti.GET_Time() << endl;
						cout << " 十Ⅰ斬煎橾熱８ : " << cur->ti.GET_Day() << endl;
						cout << " 十Ⅰ蟾婁衛除８ : " << cur->ti.GET_Overtime() << endl;
						cout << " 十Ⅰ爾 傘 蝶８ : " << cur->wp.GET_pay_bonus() << endl;
						cout << " 十㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑十\n";
						cout << " Ⅱ熱薑й Ⅰ ８ 寰曖 頂辨擊 薑�旅� 殮溘п輿撮蹂 : ";
						cin >> fix;
						if (fix.compare("餌錳檜葷") == 0) {
							cout << " Ⅱ⑷營 頂辨殮棲棻 :" << cur->wi.GET_name_worker() << endl;
							cout << " Ⅱ熱薑й 頂辨擊 殮溘п輿撮蹂 : ";
							cin >> n;
							cur->wi.SET_name_worker(n);
							system("cls");
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							cout << "                  ≧ 撩奢瞳戲煎 熱薑腎歷蝗棲棻! ≠\n";
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							break;
						}
						else if (fix.compare("儅喇錯橾") == 0) {
							cout << " Ⅱ⑷營 頂辨殮棲棻 :" << cur->wi.GET_birth() << endl;
							cout << " Ⅱ熱薑й 頂辨擊 殮溘п輿撮蹂 : ";
							cin >> n;
							cur->wi.SET_birth(n);
							system("cls");
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							cout << "                  ≧ 撩奢瞳戲煎 熱薑腎歷蝗棲棻! ≠\n";
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							break;
						}
						else if (fix.compare("輿模") == 0) {
							cout << " Ⅱ⑷營 頂辨殮棲棻 :" << cur->wi.GET_address_worker() << endl;
							cout << " Ⅱ熱薑й 頂辨擊 殮溘п輿撮蹂 : ";
							cin >> n;
							cur->wi.SET_address_worker(n);
							system("cls");
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							cout << "                  ≧ 撩奢瞳戲煎 熱薑腎歷蝗棲棻! ≠\n";
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							break;
						}
						else if (fix.compare("檜詭橾") == 0) {
							cout << " Ⅱ⑷營 頂辨殮棲棻 :" << cur->wi.GET_address_email() << endl;
							cout << " Ⅱ熱薑й 頂辨擊 殮溘п輿撮蹂 : ";
							cin >> n;
							cur->wi.SET_address_email(n);
							system("cls");
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							cout << "                  ≧ 撩奢瞳戲煎 熱薑腎歷蝗棲棻! ≠\n";
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							break;
						}
						else if (fix.compare("�瑒踰齈醽�") == 0) {
							cout << " Ⅱ⑷營 頂辨殮棲棻 :" << cur->wi.GET_data_phone() << endl;
							cout << " Ⅱ熱薑й 頂辨擊 殮溘п輿撮蹂 : ";
							cin >> n;
							cur->wi.SET_data_phone(n);
							system("cls");
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							cout << "                  ≧ 撩奢瞳戲煎 熱薑腎歷蝗棲棻! ≠\n";
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							break;
						}
						else if (fix.compare("擎ч檜葷") == 0) {
							cout << " Ⅱ⑷營 頂辨殮棲棻 :" << cur->wi.GET_name_bank() << endl;
							cout << " Ⅱ熱薑й 頂辨擊 殮溘п輿撮蹂 : ";
							cin >> n;
							cur->wi.SET_name_bank(n);
							system("cls");
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							cout << "                  ≧ 撩奢瞳戲煎 熱薑腎歷蝗棲棻! ≠\n";
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							break;
						}
						else if (fix.compare("啗謝廓��") == 0) {
							cout << " Ⅱ⑷營 頂辨殮棲棻 :" << cur->wi.GET_bank_num() << endl;
							cout << " Ⅱ熱薑й 頂辨擊 殮溘п輿撮蹂 : ";
							cin >> n;
							cur->wi.SET_bank_num(n);
							system("cls");
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							cout << "                  ≧ 撩奢瞳戲煎 熱薑腎歷蝗棲棻! ≠\n";
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							break;
						}
						else if (fix.compare("斬煎衛除") == 0) {
							cout << " Ⅱ⑷營 頂辨殮棲棻 :" << cur->ti.GET_Time() << endl;
							cout << " Ⅱ熱薑й 頂辨擊 殮溘п輿撮蹂 : ";
							cin >> m;
							cur->ti.SET_Time(m);
							system("cls");
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							cout << "                  ≧ 撩奢瞳戲煎 熱薑腎歷蝗棲棻! ≠\n";
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							break;
						}
						else if (fix.compare("斬煎橾熱") == 0) {
							cout << " Ⅱ⑷營 頂辨殮棲棻 :" << cur->ti.GET_Day() << endl;
							cout << " Ⅱ熱薑й 頂辨擊 殮溘п輿撮蹂 : ";
							cin >> m;
							cur->ti.SET_Day(m);
							system("cls");
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							cout << "                  ≧ 撩奢瞳戲煎 熱薑腎歷蝗棲棻! ≠\n";
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							break;
						}
						else if (fix.compare("蟾婁衛除") == 0) {
							cout << " Ⅱ⑷營 頂辨殮棲棻 :" << cur->ti.GET_Overtime() << endl;
							cout << " Ⅱ熱薑й 頂辨擊 殮溘п輿撮蹂 : ";
							cin >> m;
							cur->ti.SET_Overtime(m);
							system("cls");
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							cout << "                  ≧ 撩奢瞳戲煎 熱薑腎歷蝗棲棻! ≠\n";
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							break;
						}
						else if (fix.compare("爾傘蝶") == 0) {
							cout << " Ⅱ⑷營 頂辨殮棲棻 :" << cur->wp.GET_pay_bonus() << endl;
							cout << " Ⅱ熱薑й 頂辨擊 殮溘п輿撮蹂 : ";
							cin >> m;
							cur->wp.SET_pay_bonus(m);
							system("cls");
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							cout << "                  ≧ 撩奢瞳戲煎 熱薑腎歷蝗棲棻! ≠\n";
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							break;
						}
						else {
							system("cls");
							cout << "             ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n";
							cout << "             ≦    熱薑й 薑爾蒂 薑�旅� 殮溘п輿撮蹂!  ≦\n";
							cout << "             ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n\n";
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
			cout << "                ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n";
			cout << "                ≦    薑爾陛 襄營ж雖 彊蝗棲棻!   ≦\n";
			cout << "                ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n\n";
		}
		else {
			cout << "\n";
			cout << " Ⅱ熱薑 й 餌錳廓�ㄧ� 殮溘ж撮蹂 : ";
			cin >> cor2;
			system("cls");
			cur2 = head2;
			while (1) {
				if (cur2 == NULL) {
					system("cls");
					cout << "                ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n";
					cout << "                ≦    薑爾陛 襄營ж雖 彊蝗棲棻!   ≦\n";
					cout << "                ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n\n";
					break;
				}
				else {
					if (cor2 == cur2->wi.GET_num_worker()) {
						cout << " 十十十十十十十十十十十十十十十十十十十\n";
						cout << " 十      綠薑敘霜 熱薑詭景殮棲棻.    十\n";
						cout << " 十    熱薑й 薑爾蒂 殮溘п輿撮蹂!   十\n";
						cout << " 十十十十十十十十十十十十十十十十十十十\n";
						cout << " 十≦餌錳廓�ㄐ� " << cur2->wi.GET_num_worker() << endl;
						cout << " 十Ⅰ餌錳檜葷８ : " << cur2->wi.GET_name_worker() << endl;
						cout << " 十Ⅰ儅喇錯橾８ : " << cur2->wi.GET_birth() << endl;
						cout << " 十Ⅰ輿    模８ : " << cur2->wi.GET_address_worker() << endl;
						cout << " 十Ⅰ檜 詭 橾８ : " << cur2->wi.GET_address_email() << endl;
						cout << " 十Ⅰ�瑒踰齈醽ㄑ� : " << cur2->wi.GET_data_phone() << endl;
						cout << " 十Ⅰ擎ч檜葷８ : " << cur2->wi.GET_name_bank() << endl;
						cout << " 十Ⅰ啗謝廓�ㄑ�: " << cur2->wi.GET_bank_num() << endl;
						cout << " 十十十十十十十十十十十十十十十十十十十\n";
						cout << " 十         晝   罹   薑   爾        十\n";
						cout << " 十㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑十\n";
						cout << " 十Ⅰ斬煎衛除８ : " << cur2->ti.GET_Time() << endl;
						cout << " 十Ⅰ斬煎橾熱８ : " << cur2->ti.GET_Day() << endl;
						cout << " 十Ⅰ蟾婁衛除８ : " << cur2->ti.GET_Overtime() << endl;
						cout << " 十Ⅰ爾 傘 蝶８ : " << cur2->wp.GET_pay_bonus() << endl;
						cout << " 十㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑十\n";
						cout << " Ⅱ熱薑й Ⅰ ８ 寰曖 頂辨擊 薑�旅� 殮溘п輿撮蹂 : ";
						cin >> fix2;
						if (fix2.compare("餌錳檜葷") == 0) {
							cout << " Ⅱ⑷營 頂辨殮棲棻 :" << cur2->wi.GET_name_worker() << endl;
							cout << " Ⅱ熱薑й 頂辨擊 殮溘п輿撮蹂 : ";
							cin >> n;
							cur2->wi.SET_name_worker(n);
							system("cls");
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							cout << "                  ≧ 撩奢瞳戲煎 熱薑腎歷蝗棲棻! ≠\n";
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							break;
						}
						else if (fix2.compare("儅喇錯橾") == 0) {
							cout << " Ⅱ⑷營 頂辨殮棲棻 :" << cur2->wi.GET_birth() << endl;
							cout << " Ⅱ熱薑й 頂辨擊 殮溘п輿撮蹂 : ";
							cin >> n;
							cur2->wi.SET_birth(n);
							system("cls");
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							cout << "                  ≧ 撩奢瞳戲煎 熱薑腎歷蝗棲棻! ≠\n";
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							break;
						}
						else if (fix2.compare("輿模") == 0) {
							cout << " Ⅱ⑷營 頂辨殮棲棻 :" << cur2->wi.GET_address_worker() << endl;
							cout << " Ⅱ熱薑й 頂辨擊 殮溘п輿撮蹂 : ";
							cin >> n;
							cur2->wi.SET_address_worker(n);
							system("cls");
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							cout << "                  ≧ 撩奢瞳戲煎 熱薑腎歷蝗棲棻! ≠\n";
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							break;
						}
						else if (fix2.compare("檜詭橾") == 0) {
							cout << " Ⅱ⑷營 頂辨殮棲棻 :" << cur2->wi.GET_address_email() << endl;
							cout << " Ⅱ熱薑й 頂辨擊 殮溘п輿撮蹂 : ";
							cin >> n;
							cur2->wi.SET_address_email(n);
							system("cls");
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							cout << "                  ≧ 撩奢瞳戲煎 熱薑腎歷蝗棲棻! ≠\n";
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							break;
						}
						else if (fix2.compare("�瑒踰齈醽�") == 0) {
							cout << " Ⅱ⑷營 頂辨殮棲棻 :" << cur2->wi.GET_data_phone() << endl;
							cout << " Ⅱ熱薑й 頂辨擊 殮溘п輿撮蹂 : ";
							cin >> n;
							cur2->wi.SET_data_phone(n);
							system("cls");
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							cout << "                  ≧ 撩奢瞳戲煎 熱薑腎歷蝗棲棻! ≠\n";
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							break;
						}
						else if (fix2.compare("擎ч檜葷") == 0) {
							cout << " Ⅱ⑷營 頂辨殮棲棻 :" << cur2->wi.GET_name_bank() << endl;
							cout << " Ⅱ熱薑й 頂辨擊 殮溘п輿撮蹂 : ";
							cin >> n;
							cur2->wi.SET_name_bank(n);
							system("cls");
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							cout << "                  ≧ 撩奢瞳戲煎 熱薑腎歷蝗棲棻! ≠\n";
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							break;
						}
						else if (fix2.compare("啗謝廓��") == 0) {
							cout << " Ⅱ⑷營 頂辨殮棲棻 :" << cur2->wi.GET_bank_num() << endl;
							cout << " Ⅱ熱薑й 頂辨擊 殮溘п輿撮蹂 : ";
							cin >> n;
							cur2->wi.SET_bank_num(n);
							system("cls");
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							cout << "                  ≧ 撩奢瞳戲煎 熱薑腎歷蝗棲棻! ≠\n";
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							break;
						}
						else if (fix2.compare("斬煎衛除") == 0) {
							cout << " Ⅱ⑷營 頂辨殮棲棻 :" << cur2->ti.GET_Time() << endl;
							cout << " Ⅱ熱薑й 頂辨擊 殮溘п輿撮蹂 : ";
							cin >> m;
							cur2->ti.SET_Time(m);
							system("cls");
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							cout << "                  ≧ 撩奢瞳戲煎 熱薑腎歷蝗棲棻! ≠\n";
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							break;
						}
						else if (fix2.compare("斬煎橾熱") == 0) {
							cout << " Ⅱ⑷營 頂辨殮棲棻 :" << cur2->ti.GET_Day() << endl;
							cout << " Ⅱ熱薑й 頂辨擊 殮溘п輿撮蹂 : ";
							cin >> m;
							cur2->ti.SET_Day(m);
							system("cls");
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							cout << "                  ≧ 撩奢瞳戲煎 熱薑腎歷蝗棲棻! ≠\n";
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							break;
						}
						else if (fix2.compare("蟾婁衛除") == 0) {
							cout << " Ⅱ⑷營 頂辨殮棲棻 :" << cur2->ti.GET_Overtime() << endl;
							cout << " Ⅱ熱薑й 頂辨擊 殮溘п輿撮蹂 : ";
							cin >> m;
							cur2->ti.SET_Overtime(m);
							system("cls");
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							cout << "                  ≧ 撩奢瞳戲煎 熱薑腎歷蝗棲棻! ≠\n";
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							break;
						}
						else if (fix2.compare("爾傘蝶") == 0) {
							cout << " Ⅱ⑷營 頂辨殮棲棻 :" << cur2->wp.GET_pay_bonus() << endl;
							cout << " Ⅱ熱薑й 頂辨擊 殮溘п輿撮蹂 : ";
							cin >> m;
							cur2->wp.SET_pay_bonus(m);
							system("cls");
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							cout << "                  ≧ 撩奢瞳戲煎 熱薑腎歷蝗棲棻! ≠\n";
							cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
							break;
						}
						else {
							system("cls");
							cout << "             ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n";
							cout << "             ≦    熱薑й 薑爾蒂 薑�旅� 殮溘п輿撮蹂!  ≦\n";
							cout << "             ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n\n";
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
			cout << "                ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n";
			cout << "                ≦    薑爾陛 襄營ж雖 彊蝗棲棻!   ≦\n";
			cout << "                ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n\n";
		}
		else {

			cout << " Ⅱ匐儀й 餌錳廓�ㄧ� 殮溘ж撮蹂 : ";
			cin >> ser;
			system("cls");
			cur = head;
			while (1) {
				if (cur == NULL) {
					system("cls");
					cout << "                ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n";
					cout << "                ≦    薑爾陛 襄營ж雖 彊蝗棲棻!   ≦\n";
					cout << "                ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n\n";
					break;
				}
				else {
					if (ser == cur->wi.GET_num_worker()) {
						cout << " 旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n";
						cout << " 早             薑敘霜 餌錳廓�� " << cur->wi.GET_num_worker() << "廓擊 轎溘м棲棻.             早\n";
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早                  偃     檣     薑     爾                  早\n";
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早 Ⅰ餌錳檜葷 : " << cur->wi.GET_name_worker() << endl;
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早 Ⅰ儅喇錯橾 : " << cur->wi.GET_birth() << endl;
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早 Ⅰ輿    模 : " << cur->wi.GET_address_worker() << endl;
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早 Ⅰ檜 詭 橾 : " << cur->wi.GET_address_email() << endl;
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早 Ⅰ�瑒踰齈醽� : " << cur->wi.GET_data_phone() << endl;
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早 Ⅰ擎ч檜葷 : " << cur->wi.GET_name_bank() << endl;
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早 Ⅰ啗謝廓�� : " << cur->wi.GET_bank_num() << endl;
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早                  晝     罹     薑     爾                  早\n";
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早 Ⅰ錯晝 : " << cur->FullTime::GET_pay_month() << " 錳" << endl;
						cout << " 早    ≦ 衛晝 : " << cur->wp.pay_hour_pay << " 錳" << endl;
						cout << " 早    ≦ 橾и衛除 : : " << cur->ti.GET_Time() << " 衛除" << endl;
						cout << " 早    ≦ 轎斬橾熱 : " << cur->ti.GET_Day() << " 橾" << endl;
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早 Ⅰ蟾婁熱渡 : " << cur->FullTime::GET_pay_overtime() << endl;
						cout << " 早    ≦ 蟾婁斬鼠衛晝(衛晝 x 1.5) : " << cur->wp.pay_hour_pay * 1.5 << " 錳" << endl;
						cout << " 早    ≦ 蟾婁斬鼠衛除 : " << cur->ti.GET_Overtime() << " 衛除" << endl;
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早 Ⅰ衝綠 : " << cur->FullTime::GET_pay_meal() << " 錳" << endl;
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早 Ⅰ爾傘蝶 : " << cur->wp.GET_pay_bonus() << " 錳" << endl;
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早                  奢     薯     薑     爾                  早\n";
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早 Ⅰ翱旎(錯晝 x 0.045) : " << cur->FullTime::GET_pension() << " 錳" << endl;
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早 Ⅰ爾я : " << cur->FullTime::GET_insu() << endl;
						cout << " 早    ≦ 勒鬼爾я(錯晝 x 0.0306) : " << cur->GET_helinsu() << " 錳" << endl;
						cout << " 早    ≦ 堅辨爾я(錯晝 x 0.0065) : " << cur->GET_empinsu() << " 錳" << endl;
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早 Ⅰ撮旎 : " << cur->FullTime::GET_Tax() << endl;
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早                  譆     謙     薑     爾                  早\n";
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早 Ⅰ識 晝罹 : " << cur->FullTime::GET_Total() << " 錳" << endl;
						cout << " 早 Ⅰ識 奢薯 : " << cur->FullTime::GET_Cost() << " 錳" << endl;
						cout << " 早 Ⅰ褒 熱滄 : " << cur->FullTime::GET_real_pay() << " 錳" << endl;
						cout << " 曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n";
						cout << "㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑\n";
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
			cout << "                ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n";
			cout << "                ≦    薑爾陛 襄營ж雖 彊蝗棲棻!   ≦\n";
			cout << "                ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n\n";
		}
		else {

			cout << " Ⅱ匐儀й 餌錳廓�ㄧ� 殮溘ж撮蹂 : ";
			cin >> ser2;
			system("cls");
			cur2 = head2;
			while (1) {
				if (cur2 == NULL) {
					system("cls");
					cout << "                ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n";
					cout << "                ≦    薑爾陛 襄營ж雖 彊蝗棲棻!   ≦\n";
					cout << "                ≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n\n";
					break;
				}
				else {
					if (ser2 == cur2->wi.GET_num_worker()) {
						cout << " 旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n";
						cout << " 早            綠薑敘霜 餌錳廓�� " << cur2->wi.GET_num_worker() << "廓擊 轎溘м棲棻.            早\n";
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早                  偃     檣     薑     爾                  早\n";
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早 Ⅰ餌錳檜葷 : " << cur2->wi.GET_name_worker() << endl;
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早 Ⅰ儅喇錯橾 : " << cur2->wi.GET_birth() << endl;
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早 Ⅰ輿    模 : " << cur2->wi.GET_address_worker() << endl;
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早 Ⅰ檜 詭 橾 : " << cur2->wi.GET_address_email() << endl;
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早 Ⅰ�瑒踰齈醽� : " << cur2->wi.GET_data_phone() << endl;
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早 Ⅰ擎ч檜葷 : " << cur2->wi.GET_name_bank() << endl;
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早 Ⅰ啗謝廓�� : " << cur2->wi.GET_bank_num() << endl;
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早                  晝     罹     薑     爾                  早\n";
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早 Ⅰ錯晝 : " << cur2->PartTime::GET_Ppay_month() << " 錳" << endl;
						cout << " 早    ≦ 衛晝 : " << cur2->wp.pay_hour_pay << " 錳" << endl;
						cout << " 早    ≦ 橾и衛除 : : " << cur2->ti.GET_Time() << " 衛除" << endl;
						cout << " 早    ≦ 轎斬橾熱 : " << cur2->ti.GET_Day() << " 橾" << endl;
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早 Ⅰ蟾婁熱渡 : " << cur2->PartTime::GET_Ppay_overtime() << endl;
						cout << " 早    ≦ 蟾婁斬鼠衛晝(衛晝 x 1.5) : " << cur2->wp.pay_hour_pay * 1.5 << " 錳" << endl;
						cout << " 早    ≦ 蟾婁斬鼠衛除 : " << cur2->ti.GET_Overtime() << " 衛除" << endl;
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早 Ⅰ衝綠 : " << cur2->PartTime::GET_Ppay_meal() << " 錳" << endl;
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早 Ⅰ爾傘蝶 : " << cur2->wp.GET_pay_bonus() << " 錳" << endl;
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早                  奢     薯     薑     爾                  早\n";
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早 Ⅰ爾я : " << cur2->PartTime::GET_Pinsu() << endl;
						cout << " 早    ≦ 勒鬼爾я(錯晝 x 0.0306) : " << cur2->GET_Phelinsu() << " 錳" << endl;
						cout << " 早    ≦ 堅辨爾я(錯晝 x 0.0065) : " << cur2->GET_Pempinsu() << " 錳" << endl;
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早 Ⅰ撮旎 : " << cur2->PartTime::GET_PTax() << endl;
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早                  譆     謙     薑     爾                  早\n";
						cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n";
						cout << " 早 Ⅰ識 晝罹 : " << cur2->PartTime::GET_PTotal() << " 錳" << endl;
						cout << " 早 Ⅰ識 奢薯 : " << cur2->PartTime::GET_PCost() << " 錳" << endl;
						cout << " 早 Ⅰ褒 熱滄 : " << cur2->PartTime::GET_Preal_pay() << " 錳" << endl;
						cout << " 曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n";
						cout << "㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑\n";
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
	int sel; //滲熱曖 晦棟?

public:
	void menu() {
		Master ma;
		while (sel != 3) {
			int aa = 0;
			int ba = 0;
			cout << "  旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n";
			cout << "  早    ≦晝罹婦葬 Щ煎斜極≦   早\n";
			cout << "  曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭                   &    &\n";
			cout << " 旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬                玄企玄撿親~\n";
			cout << " 早                              早     &    &\n";
			cout << " 早        1.   婦 葬 濠         早     玄企玄 撿親~          &    &\n";
			cout << " 早                              早                           玄企玄\n";
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽         玄企玄撿親~\n";
			cout << " 早                              早        &    &           \n";
			cout << " 早        2.   餌    錳         早        玄企玄\n";
			cout << " 早                              早                           玄企玄撿親~\n";
			cout << " 曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽                     玄企玄\n";
			cout << " 早                              早\n";
			cout << " 早        3.   謙    猿         早                  玄企玄撿親~\n";
			cout << " 早                              早                                         玄企玄撿親~\n";
			cout << " 曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭                           玄企玄\n";
			cout << " Ⅱ鼠歙擊 ж衛啊蝗棲梱? >> ";
			cin >> sel;
			cout << "\n";
			switch (sel) {
			case 1:
				int pass;
				cout << "Ⅱ綠塵廓�ㄧ� 殮溘ж撮蹂 : ";
				cin >> pass;
				cout << "\n";
				if (pass == 1234) {
					system("cls");
					while (aa != 6) {
						int ab = 0;
						cout << "                    旨收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n";
						cout << "                    早   ﹣婦葬濠 詭景殮棲棻﹣  早\n";
						cout << "                    曲收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n";
						cout << "旨收收收收收收收收收收有收收收收收收收收收收有收收收收收收收收收收有收收收收收收收收收收有收收收收收收收收收收有收收收收收收收收收收旬\n";
						cout << "早 1. 殮溘  早 2. 轎溘  早 3. 匐儀  早 4. 熱薑  早 5. 餉薯  早 6. 詭檣  早\n";
						cout << "曲收收收收收收收收收收朴收收收收收收收收收收朴收收收收收收收收收收朴收收收收收收收收收收朴收收收收收收收收收收朴收收收收收收收收收收旭\n";
						cout << " Ⅱ鼠歙擊 ж衛啊蝗棲梱? >> ";
						cin >> aa;
						cout << "\n";
						switch (aa) {
						case 1: system("cls"); {
							while (ab != 3) {
								cout << "                     旨收收收收收收收收收收收收收收收收收收收收收收收收旬\n";
								cout << "                     早   ﹣殮溘 詭景殮棲棻﹣  早\n";
								cout << "                     曲收收收收收收收收收收收收收收收收收收收收收收收收旭\n";
								cout << "   旨收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收收收收收收收收收旬\n";
								cout << "   早   1. 薑敘霜 殮溘  早  2. 綠薑敘霜 殮溘 早    3. 檜瞪詭景    早\n";
								cout << "   曲收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收收收收收收收收收旭\n";
								cout << " Ⅱ鼠歙擊 ж衛啊蝗棲梱? >> ";
								cin >> ab;
								switch (ab) {
								case 1: system("cls");
									ma.fullinput();
									system("cls");
									cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
									cout << "                  ≧ 撩奢瞳戲煎 殮溘腎歷蝗棲棻! ≠\n";
									cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
									break;
								case 2: system("cls");
									ma.Partinput();
									system("cls");
									cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
									cout << "                  ≧ 撩奢瞳戲煎 殮溘腎歷蝗棲棻! ≠\n";
									cout << "                  ≠≧≠≧≠≧≠≧≠≧≠≧≠≧≠≧\n";
									break;
								case 3: system("cls");
									cout << "                   旨收收收收收收收 汁收收收收收收收收收 汁收收收收收收收旬\n";
									cout << "                   (        ∞    企    ∞        )\n";
									cout << "                   曲收收收收收收 企收收收收收收收收收收收 企收收收收收收旭\n";
									cout << "                    ＝   檜瞪詭景煎 給嬴骨棲棻 ＝\n";

									break;
								default:
									system("cls");
									cout << "                      ≦≦≦≦≦≦≦≦≦≦≦≦≦\n";
									cout << "                      ≦  澀跤脹 殮溘殮棲棻   ≦\n";
									cout << "                      ≦  棻衛 殮溘п輿撮蹂!  ≦\n";
									cout << "                      ≦≦≦≦≦≦≦≦≦≦≦≦≦\n\n";
								}
							}
						}break;
						case 2: system("cls");
							while (ab != 3) {
								cout << "                     旨收收收收收收收收收收收收收收收收收收收收收收收收旬\n";
								cout << "                     早   ﹣轎溘 詭景殮棲棻﹣  早\n";
								cout << "                     曲收收收收收收收收收收收收收收收收收收收收收收收收旭\n";
								cout << "   旨收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收收收收收收收收收旬\n";
								cout << "   早   1. 薑敘霜 轎溘  早  2. 綠薑敘霜 轎溘 早    3. 檜瞪詭景    早\n";
								cout << "   曲收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收收收收收收收收收旭\n";
								cout << " Ⅱ鼠歙擊 ж衛啊蝗棲梱? >> ";
								cin >> ab;
								switch (ab) {
								case 1: system("cls");  ma.FullOutput(); break;
								case 2: system("cls");  ma.PartOutput(); break;
								case 3: system("cls");
									cout << "                   旨收收收收收收收 汁收收收收收收收收收 汁收收收收收收收旬\n";
									cout << "                   (        ∞    企    ∞        )\n";
									cout << "                   曲收收收收收收 企收收收收收收收收收收收 企收收收收收收旭\n";
									cout << "                    ＝   檜瞪詭景煎 給嬴骨棲棻 ＝\n"; break;
								default:
									system("cls");
									cout << "                      ≦≦≦≦≦≦≦≦≦≦≦≦≦\n";
									cout << "                      ≦  澀跤脹 殮溘殮棲棻   ≦\n";
									cout << "                      ≦  棻衛 殮溘п輿撮蹂!  ≦\n";
									cout << "                      ≦≦≦≦≦≦≦≦≦≦≦≦≦\n\n";
								}
							}break;
						case 3:system("cls");
							while (ab != 3) {
								cout << "                     旨收收收收收收收收收收收收收收收收收收收收收收收收旬\n";
								cout << "                     早   ﹣匐儀 詭景殮棲棻﹣  早\n";
								cout << "                     曲收收收收收收收收收收收收收收收收收收收收收收收收旭\n";
								cout << "   旨收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收收收收收收收收收旬\n";
								cout << "   早   1. 薑敘霜 匐儀  早  2. 綠薑敘霜 匐儀 早    3. 檜瞪詭景    早\n";
								cout << "   曲收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收收收收收收收收收旭\n";
								cout << " Ⅱ鼠歙擊 ж衛啊蝗棲梱? >> ";
								cin >> ab;
								switch (ab) {
								case 1:	system("cls"); ma.Fullsearch(); break;
								case 2: system("cls");  ma.Partsearch(); break;
								case 3: system("cls");
									cout << "                   旨收收收收收收收 汁收收收收收收收收收 汁收收收收收收收旬\n";
									cout << "                   (        ∞    企    ∞        )\n";
									cout << "                   曲收收收收收收 企收收收收收收收收收收收 企收收收收收收旭\n";
									cout << "                    ＝   檜瞪詭景煎 給嬴骨棲棻 ＝\n";
									break;
								default:
									system("cls");
									cout << "                      ≦≦≦≦≦≦≦≦≦≦≦≦≦\n";
									cout << "                      ≦  澀跤脹 殮溘殮棲棻   ≦\n";
									cout << "                      ≦  棻衛 殮溘п輿撮蹂!  ≦\n";
									cout << "                      ≦≦≦≦≦≦≦≦≦≦≦≦≦\n\n";
								}
							}break;
						case 4: system("cls");
							while (ab != 3) {
								cout << "                     旨收收收收收收收收收收收收收收收收收收收收收收收收旬\n";
								cout << "                     早   ﹣熱薑 詭景殮棲棻﹣  早\n";
								cout << "                     曲收收收收收收收收收收收收收收收收收收收收收收收收旭\n";
								cout << "   旨收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收收收收收收收收收旬\n";
								cout << "   早   1. 薑敘霜 熱薑  早  2. 綠薑敘霜 熱薑 早    3. 檜瞪詭景    早\n";
								cout << "   曲收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收收收收收收收收收旭\n";
								cout << " Ⅱ鼠歙擊 ж衛啊蝗棲梱? >> ";
								cin >> ab;
								switch (ab) {
								case 1:	system("cls"); ma.Fullcorrect();
									break;
								case 2: system("cls");  ma.Partcorrect();
									break;
								case 3: system("cls");
									cout << "                   旨收收收收收收收 汁收收收收收收收收收 汁收收收收收收收旬\n";
									cout << "                   (        ∞    企    ∞        )\n";
									cout << "                   曲收收收收收收 企收收收收收收收收收收收 企收收收收收收旭\n";
									cout << "                    ＝   檜瞪詭景煎 給嬴骨棲棻 ＝\n";
									break;
								default:
									system("cls");
									cout << "                      ≦≦≦≦≦≦≦≦≦≦≦≦≦\n";
									cout << "                      ≦  澀跤脹 殮溘殮棲棻   ≦\n";
									cout << "                      ≦  棻衛 殮溘п輿撮蹂!  ≦\n";
									cout << "                      ≦≦≦≦≦≦≦≦≦≦≦≦≦\n\n";
								}
							}break;
						case 5: system("cls");
							while (ab != 3) {
								cout << "                     旨收收收收收收收收收收收收收收收收收收收收收收收收旬\n";
								cout << "                     早   ﹣餉薯 詭景殮棲棻﹣  早\n";
								cout << "                     曲收收收收收收收收收收收收收收收收收收收收收收收收旭\n";
								cout << "   旨收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收收收收收收收收收旬\n";
								cout << "   早   1. 薑敘霜 餉薯  早  2. 綠薑敘霜 餉薯 早    3. 檜瞪詭景    早\n";
								cout << "   曲收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收收收收收收收收收旭\n";
								cout << " Ⅱ鼠歙擊 ж衛啊蝗棲梱? >> ";
								cin >> ab;
								switch (ab) {
								case 1:	system("cls"); ma.Fulldele(); break;
								case 2: system("cls");  ma.Partdele(); break;
								case 3: system("cls");
									cout << "                   旨收收收收收收收 汁收收收收收收收收收 汁收收收收收收收旬\n";
									cout << "                   (        ∞    企    ∞        )\n";
									cout << "                   曲收收收收收收 企收收收收收收收收收收收 企收收收收收收旭\n";
									cout << "                    ＝   檜瞪詭景煎 給嬴骨棲棻 ＝\n";
									break;
								default:
									system("cls");
									cout << "                      ≦≦≦≦≦≦≦≦≦≦≦≦≦\n";
									cout << "                      ≦  澀跤脹 殮溘殮棲棻   ≦\n";
									cout << "                      ≦  棻衛 殮溘п輿撮蹂!  ≦\n";
									cout << "                      ≦≦≦≦≦≦≦≦≦≦≦≦≦\n\n";
								}
							}break;
						case 6: system("cls");
							cout << "  旨收收收收收收收 汁收收收收收收收收收 汁收收收收收收收旬\n";
							cout << "  (        ∞    企    ∞        )\n";
							cout << "  曲收收收收收收 企收收收收收收收收收收收 企收收收收收收旭\n";
							cout << "   ＝   詭檣詭景煎 給嬴骨棲棻 ＝\n"; break;
						default:
							system("cls");
							cout << "                      ≦≦≦≦≦≦≦≦≦≦≦≦≦\n";
							cout << "                      ≦  澀跤脹 殮溘殮棲棻   ≦\n";
							cout << "                      ≦  棻衛 殮溘п輿撮蹂!  ≦\n";
							cout << "                      ≦≦≦≦≦≦≦≦≦≦≦≦≦\n\n";
						}

					}

				}
				else {
					system("cls");
					cout << "≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n";
					cout << "≦      綠塵廓�ㄟ� ぎ溜蝗棲棻     ≦\n";
					cout << "≦       棻衛 殮溘п 輿撮蹂!      ≦\n";
					cout << "≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦≦\n\n";
				}
				break;
			case 2: system("cls");
				while (aa != 2) {
					int ac = 0;
					cout << "    旨收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n";
					cout << "    早   ﹣餌  錳 詭景殮棲棻﹣  早\n";
					cout << "    曲收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n";
					cout << "旨收收收收收收收收收收收收收收收收收有收收收收收收收收收收收收收收收收收旬\n";
					cout << "早   1. 薑爾爾晦   早     2. 詭檣     早\n";
					cout << "曲收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收收收收收收收旭\n";
					cout << " Ⅱ鼠歙擊 ж衛啊蝗棲梱? >> ";
					cin >> aa;
					cout << "\n";
					switch (aa) {
					case 1:system("cls");
						while (ac != 3) {

							cout << "                  旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n";
							cout << "                  早    ﹣薑爾爾晦 詭景殮棲棻﹣    早\n";
							cout << "                  曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n";
							cout << "   旨收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收收收收收收收收收旬\n";
							cout << "   早     1. 薑敘霜     早     2. 綠薑敘霜    早    3. 檜瞪詭景    早\n";
							cout << "   曲收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收收收收收收收收收旭\n";
							cout << " Ⅱ堅辨⑽鷓蒂 摹鷗ж撮蹂 >> ";
							cin >> ac;
							cout << "\n";
							switch (ac)
							{
							case 1:  system("cls"); ma.Fullsearch(); break;
							case 2:  system("cls"); ma.Partsearch(); break;
							case 3: system("cls");
								cout << "   旨收收收收收收收 汁收收收收收收收收收 汁收收收收收收收旬\n";
								cout << "   (        ∞    企    ∞        )\n";
								cout << "   曲收收收收收收 企收收收收收收收收收收收 企收收收收收收旭\n";
								cout << "    ＝  檜瞪詭景煎 給嬴骨棲棻  ＝\n"; break;
							default:
								system("cls");
								cout << "                      ≦≦≦≦≦≦≦≦≦≦≦≦≦\n";
								cout << "                      ≦  澀跤脹 殮溘殮棲棻   ≦\n";
								cout << "                      ≦  棻衛 殮溘п輿撮蹂!  ≦\n";
								cout << "                      ≦≦≦≦≦≦≦≦≦≦≦≦≦\n\n";
							}
						}
						break;
					case 2:
						system("cls");
						cout << "  旨收收收收收收收 汁收收收收收收收收收 汁收收收收收收收旬\n";
						cout << "  (        ∞    企    ∞        )\n";
						cout << "  曲收收收收收收 企收收收收收收收收收收收 企收收收收收收旭\n";
						cout << "   ＝   詭檣詭景煎 給嬴骨棲棻 ＝\n"; break;
					default:
						system("cls");
						cout << "     ≦≦≦≦≦≦≦≦≦≦≦≦≦\n";
						cout << "     ≦  澀跤脹 殮溘殮棲棻   ≦\n";
						cout << "     ≦  棻衛 殮溘п輿撮蹂!  ≦\n";
						cout << "     ≦≦≦≦≦≦≦≦≦≦≦≦≦\n\n";
					}
				}
				break;
			case 3:
				system("cls");
				for (int i = 0; i < 25; i++) {
					cout << "\n\n\n\n\n\n";
					cout << "                 ﹥                                ﹤\n";
					cout << "                   ﹤﹥﹤﹥﹤﹥﹤﹥﹤﹥﹤﹥﹤﹥﹤﹥\n";
					cout << "                   ﹥                            ﹤\n";
					cout << "                   ﹤ 婦葬Щ煎斜極擊 謙猿м棲棻. ﹥\n";
					cout << "                   ﹥                            ﹤\n";
					cout << "                   ﹤﹥﹤﹥﹤﹥﹤﹥﹤﹥﹤﹥﹤﹥﹤﹥\n";
					cout << "                 ﹤                                ﹤\n";
					Sleep(100);
					system("cls");
					cout << "\n\n\n\n\n\n";
					cout << "                 ﹤                                ﹥\n";
					cout << "                   ﹥﹤﹥﹤﹥﹤﹥﹤﹥﹤﹥﹤﹥﹤﹥﹤\n";
					cout << "                   ﹤                            ﹥\n";
					cout << "                   ﹥ 婦葬Щ煎斜極擊 謙猿м棲棻. ﹤\n";
					cout << "                   ﹤                            ﹥\n";
					cout << "                   ﹥﹤﹥﹤﹥﹤﹥﹤﹥﹤﹥﹤﹥﹤﹥﹤\n";
					cout << "                 ﹤                                ﹤\n\n";
					Sleep(100);
					system("cls");
					cout << "\n\n\n\n\n\n";
					cout << "                 ﹤                                ﹤\n";
					cout << "                   ﹤﹥﹤﹥﹤﹥﹤﹥﹤﹥﹤﹥﹤﹥﹤﹥\n";
					cout << "                   ﹥                            ﹤\n";
					cout << "                   ﹤ 婦葬Щ煎斜極擊 謙猿м棲棻. ﹥\n";
					cout << "                   ﹥                            ﹤\n";
					cout << "                   ﹤﹥﹤﹥﹤﹥﹤﹥﹤﹥﹤﹥﹤﹥﹤﹥\n";
					cout << "                 ﹤                                ﹥\n\n";
					Sleep(100);
					system("cls");
					cout << "\n\n\n\n\n\n";
					cout << "                 ﹤                                ﹤\n";
					cout << "                   ﹥﹤﹥﹤﹥﹤﹥﹤﹥﹤﹥﹤﹥﹤﹥﹤\n";
					cout << "                   ﹤                            ﹥\n";
					cout << "                   ﹥ 婦葬Щ煎斜極擊 謙猿м棲棻. ﹤\n";
					cout << "                   ﹤                            ﹥\n";
					cout << "                   ﹥﹤﹥﹤﹥﹤﹥﹤﹥﹤﹥﹤﹥﹤﹥﹤\n";
					cout << "                 ﹥                                ﹤\n\n";
					Sleep(100);
					system("cls");

				}
				break;
			default:
				system("cls");
				cout << "    ≦≦≦≦≦≦≦≦≦≦≦≦≦\n";
				cout << "    ≦  澀跤脹 殮溘殮棲棻   ≦\n";
				cout << "    ≦  棻衛 殮溘п輿撮蹂!  ≦\n";
				cout << "    ≦≦≦≦≦≦≦≦≦≦≦≦≦\n\n";
			}
		}
	}
};
//------------------------------------------------------------------------------------------------------------------
void main() {
	//List a;

	cout << "          \n煎註醞....\n";
	for (int i = 0; i < 1; i++) {

		cout << "﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤ (0%)" << flush;

		Sleep(100);
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b﹥﹤﹤﹤﹤﹤﹤﹤﹤﹤ (10%)" << flush;

		Sleep(100);
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b﹥﹥﹤﹤﹤﹤﹤﹤﹤﹤ (20%)" << flush;

		Sleep(100);
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b﹥﹥﹥﹤﹤﹤﹤﹤﹤﹤ (30%)" << flush;

		Sleep(100);
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b﹥﹥﹥﹥﹤﹤﹤﹤﹤﹤ (40%)" << flush;

		Sleep(100);
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b﹥﹥﹥﹥﹥﹤﹤﹤﹤﹤ (50%)" << flush;

		Sleep(100);
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b﹥﹥﹥﹥﹥﹥﹤﹤﹤﹤ (60%)" << flush;

		Sleep(100);
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b﹥﹥﹥﹥﹥﹥﹥﹤﹤﹤ (70%)" << flush;

		Sleep(100);
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b﹥﹥﹥﹥﹥﹥﹥﹥﹤﹤ (80%)" << flush;

		Sleep(100);
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b﹥﹥﹥﹥﹥﹥﹥﹥﹥﹤ (90%)" << flush;

		Sleep(100);
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ (100%)\n" << flush;
		cout << "煎註諫猿!";
		break;
	}
	Sleep(1000);

	system("cls");
	Menu sele;
	sele.menu();
}