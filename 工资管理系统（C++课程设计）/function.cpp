#include<iostream>
#include<fstream>
using namespace std;
#include<string>
#include"class.h"
ostream& operator<<(ostream&output, formal_staff&a)
{
	cout << "��ţ�";
	output << a.num << endl;
	cout << "������";
	output << a.name << endl;
	cout << "�Ա�";
	output << a.sex << endl;
	cout << "���䣺";
	output << a.age << endl;
	cout << "��ͥסַ��";
	output << a.address << endl;
	cout << "����ְ����:";
	output << a.ori_salary << endl;
	cout << "��λ������";
	output << a.allowance << endl;
	cout << "���Ͻ�:";
	output << a.pension << endl;
	cout << "ס��������:";
	output << a.housing_fund << endl;
	cout << "����˰:";
	output << a.tax << endl;
	cout << "ҽ�Ʊ���:";
	output << a.insurance << endl;
	cout << "ʵ������:";
	output << a.calculate_salary() << endl;
	return output;
}
istream& operator>>(istream&input, formal_staff&a)
{
	for(;;)
	{
		cout << "��ţ�";
		input >> a.num;
		if (a.num>0)
			break;
		else
			cerr << "�������������������롣" << endl;
	}
	cout << "������";
	input >> a.name;
	for (;;)
	{
		cout << "�Ա�";
		input >> a.sex;
		if (a.sex == "��" || a.sex == "Ů")
			break;
		else
			cerr << "�Ա�����������������롣" << endl;
	};
	for (;;)
	{
		cout << "���䣺";
		input >> a.age;
		if (a.age>0)
			break;
		else
			cerr << "��������������������롣" << endl;
	}
	cout << "��ͥסַ��";
	input >> a.address;
	for (;;)
	{
		cout << "����ְ����:";
		input >> a.ori_salary;
		if (a.ori_salary>0)
			break;
		else
			cerr << "����ְ��������������������롣" << endl;
	}
	for (;;)
	{
		cout << "��λ������";
		input >> a.allowance;
		if (a.allowance>0)
			break;
		else
			cerr << "��λ��������������������롣" << endl;
	}
	for (;;)
	{
		cout << "���Ͻ�:";
		input >> a.pension;
		if (a.pension>0)
			break;
		else
			cerr << "���Ͻ�����������������롣" << endl;
	}
	for (;;)
	{
		cout << "ס��������:";
		input >> a.housing_fund;
		if (a.housing_fund>0)
			break;
		else
			cerr << "ס������������������������롣" << endl;
	}
	for (;;)
	{
		cout << "����˰:";
		input >> a.tax;
		if (a.tax>0)
			break;
		else
			cerr << "����˰����������������롣" << endl;
	}
	for (;;)
	{
		cout << "ҽ�Ʊ���:";
		input >> a.insurance;
		if (a.insurance>0)
			break;
		else
			cerr << "ҽ�Ʊ�������������������롣" << endl;
	}
	
	return input;
}
ostream& operator<<(ostream&output, informal_staff&a)
{
	cout << "��ţ�";
	output << a.num << endl;
	cout << "������";
	output << a.name << endl;
	cout << "�Ա�";
	output << a.sex << endl;
	cout << "���䣺";
	output << a.age << endl;
	cout << "��ͥסַ��";
	output << a.address << endl;
	cout << "����ְ����:";
	output << a.ori_salary << endl;
	cout << "����:";
	output << a.bonus << endl;
	cout << "����˰:";
	output << a.tax << endl;
	cout << "ʵ������:";
	output << a.calculate_salary() << endl;
	return output;
}
istream& operator>>(istream&input, informal_staff&a)
{
	for (;;)
	{
		cout << "��ţ�";
		input >> a.num;
		if (a.num>0)
			break;
		else
			cerr << "�������������������롣" << endl;
	}
	cout << "������";
	input >> a.name;
	while (1)
	{
		cout << "�Ա�";
		input >> a.sex;
		if (a.sex == "��" || a.sex == "Ů")
			break;
		else
			cerr << "�Ա�����������������롣" << endl;
	};
	for (;;)
	{
		cout << "���䣺";
		input >> a.age;
		if (a.age>0)
			break;
		else
			cerr << "��������������������롣" << endl;
	}
	cout << "��ͥסַ��";
	input >> a.address;
	for (;;)
	{
		cout << "����ְ����:";
		input >> a.ori_salary;
		if (a.ori_salary>0)
			break;
		else
			cerr << "����ְ��������������������롣" << endl;
	}
	for (;;)
	{
		cout << "����";
		input >> a.bonus;
		if (a.bonus>0)
			break;
		else
			cerr << "��������������������롣" << endl;
	}
	for (;;)
	{
		cout << "����˰:";
		input >> a.tax;
		if (a.tax>0)
			break;
		else
			cerr << "����˰����������������롣" << endl;
	}
	return input;
}
float informal_staff::calculate_salary()
{
	salary = ori_salary + bonus - tax;
	return salary;
}
float formal_staff::calculate_salary()
{
	salary = ori_salary + allowance - pension - housing_fund - tax - insurance;
	return salary;
}
//----------------------------------------------------------------------------------------
void formal_staff::modify_num_formal() {
	cin >> num;
}
void informal_staff::modify_num_informal()
{
	cin >> num;
}
//�¶���ĺ���,�����޸�num��ֵ

//�޸Ĳ�����ʽ������
void formal_staff::modify_formal()
{
loop_m:
	cout << "��ѡ��Ҫ�޸ĵ���Ŀ:" << endl;
	cout << "1.���" << endl;
	cout << "2.����" << endl;
	cout << "3.�Ա�" << endl;
	cout << "4.����" << endl;
	cout << "5.��ͥסַ" << endl;
	cout << "6.����ְ����" << endl;
	cout << "7.��λ����" << endl;
	cout << "8.���Ͻ�" << endl;
	cout << "9.ס��������" << endl;
	cout << "10.����˰" << endl;
	cout << "11.ҽ�Ʊ���" << endl;
	int i;
	cin >> i;
	switch (i)
	{
	case 1:
		cin >> this->num; break;
	case 2:
		cin >> this->name; break;
	case 3:
		cin >> this->sex; break;
	case 4:
		cin >> this->age; break;
	case 5:
		cin >> this->address; break;
	case 6:
		cin >> this->ori_salary; break;
	case 7:
		cin >> this->allowance; break;
	case 8:
		cin >> this->pension; break;
	case 9:
		cin >> this->housing_fund; break;
	case 10:
		cin >> this->tax; break;
	case 11:
		cin >> this->insurance; break;
	default:
		cout << "����������������롣" << endl;
		goto loop_m;
		break;
	}
	cout << "�޸ĳɹ���" << endl;
}

//�޸Ĳ��ַ���ʽ��
void informal_staff::modify_informal()
{
loop_n:
	cout << "��ѡ��Ҫ�޸ĵ���Ŀ:" << endl;
	cout << "1.���" << endl;
	cout << "2.����" << endl;
	cout << "3.�Ա�" << endl;
	cout << "4.����" << endl;
	cout << "5.��ͥסַ" << endl;
	cout << "6.����ְ����" << endl;
	cout << "7.����" << endl;
	cout << "8.����˰" << endl;
	int i;
	cin >> i;
	switch (i)
	{
	case 1:
		cin >> this->num; break;
	case 2:
		cin >> this->name; break;
	case 3:
		cin >> this->sex; break;
	case 4:
		cin >> this->age; break;
	case 5:
		cin >> this->address;break;
	case 6:
		cin >> this->ori_salary;break;
	case 7:
		cin >> this->bonus; break;
	case 8:
		cin >> this->tax; break;
	default:
		cout << "����������������롣" << endl;
		goto loop_n;
		break;
	}
	cout << "�޸ĳɹ���" << endl;
}

//��ʼ¼����ʽ������
formal_staff* input_formal_staff(formal_staff* head)
{
	formal_staff *p, *q;
	p = q = new formal_staff;
	char k = 'y';  //�ж��Ƿ��������
	if (p == NULL || q == NULL)
	{
		cerr << "�����ڴ�ʧ�ܣ�";
		system("pause");
		exit(0);
	}
	cout << "��ʼ¼�����ݣ�" << endl;
	//cin >> *p
	//cout << "¼��ɹ���" << endl;
	int i = 1;
	while (k == 'y' || k == 'Y')
	{

		cin >> *p;
	
		if (i == 1)
			head->next = p;
		else
			q->next = p;
		q = p;
		//�޸Ĳ��ִӴ˿�ʼ������Ϊ����ӵĲ��֣�--------------------------------------------------
		formal_staff *m = head->next;
		while (m!=q)
		{
			if (p->getnum() == m->getnum())
			{
				mark_input:
				cout << "��Ų����ظ��������������ţ�";
				cout << "�����룺";
				int i = p->getnum();
				p->modify_num_formal();//�������ʱ�����¶���ĺ������ڱ��ļ������ж��塣
				if (p->getnum() == i)
					goto mark_input;
				break;
			}
			m = m->next;
		}
		//�����ڴˣ���ʱ��ͬ������׸����------------------------------------------------------------------------------
		p = new formal_staff;
		if (p == NULL)
		{
			cerr << "�쳣����";
			system("pause");
			exit(0);
		}

		cout << "¼��ɹ���" << endl;
		cout << "�Ƿ�������룿����Ϊy/����Ϊn��" << endl;
		cin >> k;
		if (k == 'y')
			i++;
		system("cls");

	}
	cout << "¼�����,��¼���ˣ�" << i << "��ְ������Ϣ" << endl;
	p->next = NULL;
	return head;
}

//��ʼ¼����ʱ������
informal_staff* input_informal_staff(informal_staff* head)
{
	informal_staff *p, *q;
	p = q = new informal_staff;
	char k = 'y';  //�ж��Ƿ��������
	if (p == NULL || q == NULL)
	{
		cerr << "�����ڴ�ʧ�ܣ�";
		system("pause");
		exit(0);
	}
	cout << "��ʼ¼�����ݣ�" << endl;
	//cin >> *p
	//cout << "¼��ɹ���" << endl;
	int i = 1;
	while (k == 'y' || k == 'Y')
	{
		cin >> *p;
		if (i == 1)
			head->next = p;
		else
			q->next = p;
		q = p;
		//------------------------------------------------------------------------------------------------
		informal_staff *m = head->next;
		while (m != q)
		{
			if (p->getnum() == m->getnum())
			{
			mark_input2:
				cout << "��Ų����ظ��������������ţ�";
				cout << "�����룺";
				int i = p->getnum();
				p->modify_num_informal();//�������ʱ�����¶���ĺ������ڱ��ļ������ж��塣
				if (p->getnum() == i)
					goto mark_input2;
				break;
			}
			m = m->next;
		}
		//--------------------------------------------------------------------------------------------------
		p = new informal_staff;
		if (p == NULL)
		{
			cerr << "�쳣����";
			system("pause");
			exit(0);
		}

		cout << "¼��ɹ���" << endl;
		cout << "�Ƿ�������룿����Ϊy/����Ϊn��" << endl;
		cin >> k;
		if (k == 'y')
			i++;
		system("cls");

	}
	cout << "¼�����,��¼���ˣ�" << i << "��ְ������Ϣ" << endl;
	p->next = NULL;
	return head;
}

//����ĳ����ʽ������
formal_staff* seek_formal_staff(formal_staff* head)
{
	if (head->next == NULL)
	{
		cerr << "������������!���ȷ���������������������(���߶�ȡ�ļ�����)��" << endl;
		return head;

	}
	while (1)
	{
		cout << "��ѡ���ѯ��ʽ��" << endl;
		cout << "��Ų�ѯ�밴(1)��������ѯ�밴(2)." << endl;
		int i;
		cin >> i;
		if (!(i == 1 || i == 2))
		{
			cerr << "�����������������" << endl;
			continue;
		}
		formal_staff *p = head->next;
		int targetnum;
		string targetname;
		switch (i)
		{
		case 1:
		{
		loop1:
			cout << "�������ţ�" << endl;
			cin >> targetnum;
			p = head->next;
			while (p->getnum() != targetnum)
			{
				p = p->next;
				if (p == NULL)
					break;
			}
			if (p == NULL)
			{
				cout << "û��������ݣ����������룡" << endl;
				goto loop1;
			}
			return p;
			break;
		}
		case 2:
		{
		loop2:
			cout << "������������" << endl;
			cin >> targetname;
			p = head->next;
			while (p->getname() != targetname)
			{
				p = p->next;
				if (p == NULL)
					break;
			}
			if (p == NULL)
			{
				cout << "û��������ݣ����������룡" << endl;
				goto loop2;
			}
			return p;
			break;
		}
		default:
		{
			cerr << "�쳣���󣡣����ϱ�����Ա����" << endl;
			system("pause");
			exit(0);
			break;

		}
		}
		break;
	}

}

//����ĳ����ʱ��������
informal_staff* seek_informal_staff(informal_staff* head)
{
	if (head->next == NULL)
	{
		cerr << "������������!���ȷ���������������������(���߶�ȡ�ļ�����)��" << endl;
		return head;
	}
	while (1)
	{
		cout << "��ѡ���ѯ��ʽ��" << endl;
		cout << "��Ų�ѯ�밴(1)��������ѯ�밴(2)." << endl;
		int i;
		cin >> i;
		if (!(i == 1 || i == 2))
		{
			cerr << "�����������������" << endl;
			continue;
		}
		informal_staff *p = head->next;
		int targetnum;
		string targetname;
		switch (i)
		{
		case 1:
		{
		loop1:
			cout << "�������ţ�" << endl;
			cin >> targetnum;
			p = head->next;
			while (p->getnum() != targetnum)
			{
				p = p->next;
				if (p == NULL)
					break;
			}
			if (p == NULL)
			{
				cout << "û��������ݣ����������룡" << endl;
				goto loop1;
			}
			return p;
			break;
		}
		case 2:
		{
		loop2:
			cout << "������������" << endl;
			cin >> targetname;
			p = head->next;
			while (p->getname() != targetname)
			{
				p = p->next;
				if (p == NULL)
					break;
			}
			if (p == NULL)
			{
				cout << "û��������ݣ����������룡" << endl;
				goto loop2;
			}
			return p;
			break;
		}
		default:
		{
			cerr << "�쳣���󣡣����ϱ�����Ա����" << endl;
			system("pause");
			exit(0);
			break;

		}
		}
		break;
	}

}

//����ĳ����ʽ��������
formal_staff* insert_formal_staff(formal_staff* head)
{
	if (head->next == NULL)
	{
		cerr << "������������!���ȷ���������������������(���߶�ȡ�ļ�����)��" << endl;
		return head;
	}
	formal_staff *p, *q;

	cout << "������һ���µ���ʽְ�����ݣ�" << endl;
	p = new formal_staff;
	/*if (p->next == NULL)
	{
	cerr << "�쳣����(�ϱ�����Ա����)" << endl;
	system("pause");
	exit(0);
	}*/
	cin >> *p;
	system("cls");
	cout << "¼��ɹ���" << endl;
	cout << "���ʲ���������֮��?" << endl;
	q = seek_formal_staff(head);
	p->next = q->next;
	q->next = p;
	system("cls");
	cout << "����ɹ���";
	return head;
}

//����ĳ����ʱ��������
informal_staff* insert_informal_staff(informal_staff* head)
{
	if (head->next == NULL)
	{
		cerr << "������������!���ȷ���������������������(���߶�ȡ�ļ�����)��" << endl;
		return head;
	}
	informal_staff *p, *q;

	cout << "������һ���µ���ʱ�����ݣ�" << endl;
	p = new informal_staff;
	/*if (p->next == NULL)
	{
	cerr << "�쳣����(�ϱ�����Ա����)" << endl;
	system("pause");
	exit(0);
	}*/
	cin >> *p;
	cout << "¼��ɹ���" << endl;
	cout << "���ʲ���������֮��" << endl;
	q = seek_informal_staff(head);
	p->next = q->next;
	q->next = p;
	system("cls");
	cout << "����ɹ���";
	return head;
}

//ɾ��ĳ����ʽ��������
formal_staff* del_formal_staff(formal_staff *head, formal_staff* del_head)
{
	if (head->next == NULL)//�жϻ������Ƿ�������  
	{
		cerr << "������������!���ȷ���������������������(���߶�ȡ�ļ�����)��" << endl;
		return head;
	}
	formal_staff *p, *q;
loop:
	cout << "��ѡ��ɾ���ķ�ʽ��" << endl;
	cout << "ͨ�����ɾ����1����ͨ������ɾ����2��" << endl;
	int i;
	cin >> i;
	if (!(i == 1 || i == 2))
	{
		cout << "����������������롣" << endl;
		goto loop;
	}
	p = head->next;
	q = head;
	int targetNum;
	string targetName;
	switch (i)
	{
	case 1:
	{
	mark1:
		p = head->next;
		q = head;
		cout << "�������ţ�" << endl;
		cin >> targetNum;
		while (p->getnum() != targetNum)
		{

			q = p;
			p = p->next;
			if (p == NULL)
				break;

		}
		if (p == NULL)
		{
			cerr << "û��������ݣ����������룡" << endl;
			goto mark1;
		}
		break;
	}
	case 2:
	{
	mark2:
		p = head->next;
		q = head;
		cout << "������������" << endl;
		cin >> targetName;
		while (p->getname() != targetName)
		{
			q = p;
			p = p->next;
			if (p == NULL)
				break;

		}
		if (p == NULL)
		{
			cerr << "û��������ݣ����������룡" << endl;
			goto mark2;
		}
		break;
	}
	default:
	{
		cerr << "�쳣���󣡣����ϱ�����Ա����" << endl;
		system("pause");
		exit(0);
		break;
	}
	}
	i = 0;
	while (1)
	{
		cout << "�Ƿ�ȷ��ɾ�������밴��1���� ���밴��2��" << endl;
		cin >> i;
		if (i == 1)
		{
			q->next = p->next;
			cout << "ɾ���ɹ���" << endl;
			break;
		}
		else if (i == 2)
		{
			cout << "ȡ���ɹ���" << endl;
			break;
			return head;
		}
		else
		{
			cout << "����������������롣" << endl;
			continue;
		}

	}

	q = del_head;
	while (q->next != NULL)
	{
		q = q->next;
	}
	q->next = p;
	p->next = NULL;

	return head;

}

//ɾ��ĳ����ʱ��������
informal_staff* del_informal_staff(informal_staff *head, informal_staff* del_head)
{
	if (head->next == NULL)//�жϻ������Ƿ�������  
	{
		cerr << "������������!���ȷ���������������������(���߶�ȡ�ļ�����)��" << endl;
		return head;
	}
	informal_staff *p, *q;
loop:
	cout << "��ѡ��ɾ���ķ�ʽ��" << endl;
	cout << "ͨ�����ɾ����1����ͨ������ɾ����2��" << endl;
	int i;
	cin >> i;
	if (!(i == 1 || i == 2))
	{
		cout << "����������������롣" << endl;
		goto loop;
	}
	p = head->next;
	q = head;
	int targetNum;
	string targetName;
	switch (i)
	{
	case 1:
	{
	mark1:
		p = head->next;
		q = head;
		cout << "�������ţ�" << endl;
		cin >> targetNum;
		while (p->getnum() != targetNum)
		{
			q = p;
			p = p->next;
			if (p == NULL)
				break;

		}
		if (p == NULL)
		{
			cerr << "û��������ݣ����������룡" << endl;
			goto mark1;
		}
		break;
	}
	case 2:
	{
	mark2:
		p = head->next;
		q = head;
		cout << "������������" << endl;
		cin >> targetName;
		while (p->getname() != targetName)
		{
			q = p;
			p = p->next;
			if (p == NULL)
				break;

		}
		if (p == NULL)
		{
			cerr << "û��������ݣ����������룡" << endl;
			goto mark2;
		}
		break;
	}
	default:
	{
		cerr << "�쳣���󣡣����ϱ�����Ա����" << endl;
		system("pause");
		exit(0);
		break;
	}
	}
	i = 0;
	while (1)
	{
		cout << "�Ƿ�ȷ��ɾ�������밴��1���� ���밴��2��" << endl;
		cin >> i;
		if (i == 1)
		{
			q->next = p->next;
			cout << "ɾ���ɹ���" << endl;
			break;
		}
		else if (i == 2)
		{
			cout << "ȡ���ɹ���" << endl;
			break;
		}
		else
		{
			cout << "����������������롣" << endl;
			continue;
		}
	}

	q = del_head;
	while (q->next != NULL)
	{
		q = q->next;
	}
	q->next = p;
	p->next = NULL;
	return head;

}

//���������ʽ������
void print_formal_staff(formal_staff *head)
{
	formal_staff  *p = head->next;
	if (head->next == NULL)
	{
		cerr << "����!�������������ݣ�" << endl;
		cerr << "����ϵ����Ա����" << endl;
	}
	while (p != NULL)
	{
		cout << *p << endl;
		p = p->next;
	}
}

//���������ʱ������
void print_informal_staff(informal_staff *head)
{
	informal_staff  *p = head->next;
	if (head->next == NULL)
	{
		cerr << "����!�������������ݣ�" << endl;
		cerr << "����ϵ����Ա����" << endl;
	}
	while (p != NULL)
	{
		cout << *p << endl;
		p = p->next;
	}
}

//�޸���ʽ��������
formal_staff* modify_formal_staff(formal_staff *head)
{
	formal_staff *p, *q;
	cout << "�������Ҫ�޸ĵ���ʽ����" << endl;
	p = seek_formal_staff(head);
	if (p == head)
		return head;
	cout << *p;
	q = new formal_staff;
	q->next = p->next;
	if (q == NULL)
	{
		cerr << "����!(�����ڴ�ʧ��)" << endl;
		cerr << "����ϵ����Ա�����" << endl;
		system("pause");
		exit(0);
	}

	//---���޸�
	/*cout << "��ѡ���޸ķ�ʽ��" << endl;
	cout << "1.ȫ���޸�" << endl;
	cout << "2.�����޸�" << endl;*/

	cout << "���޸ģ�" << endl;
	cin >> *q;
	int i = 0;
mark:
	cout << "ȷ���޸��밴��1����ȡ���밴��2��" << endl;
	cin >> i;
	if (i == 1)
	{
		*p = *q;
		system("cls");
		cout << "�޸ĳɹ���" << endl;
	}
	else if (i == 2)
	{
		cout << "ȡ���ɹ���" << endl;
		delete p;
	}
	else
	{
		cout << "�����������������룡" << endl;
		goto mark;
	}


}

//�޸���ʱ��������
informal_staff* modify_informal_staff(informal_staff *head)
{
	informal_staff *p, *q;
	cout << "�������Ҫ�޸ĵ���ʱ����" << endl;
	p = seek_informal_staff(head);
	if (p == head)
		return head;
	q = new informal_staff;
	q->next = p->next;
	if (q == NULL)
	{
		cerr << "����!(�����ڴ�ʧ��)" << endl;
		cerr << "����ϵ����Ա�����" << endl;
		system("pause");
		exit(0);
	}

	//---���޸�
	/*cout << "��ѡ���޸ķ�ʽ��" << endl;
	cout << "1.ȫ���޸�" << endl;
	cout << "2.�����޸�" << endl;*/

	cout << "���޸ģ�" << endl;
	cin >> *q;
	int i = 0;
mark:
	cout << "ȷ���޸��밴��1����ȡ���밴��2��" << endl;
	cin >> i;
	if (i == 1)
	{
		*p = *q;
		system("cls");
		cout << "�޸ĳɹ���" << endl;
	}
	else if (i == 2)
	{
		cout << "ȡ���ɹ���" << endl;
		delete p;
	}
	else
	{
		cout << "�����������������룡" << endl;
		goto mark;
	}


}

//ͳ����ʽ��������
formal_staff* statistical_formal_staff(formal_staff *head)
{

	if (head->next == NULL)
	{
		cerr << "���󣡣������������ݣ��뷵���������������ݻ��߶�ȡ���ݣ�" << endl;
		return head;
	}
	formal_staff *p = head->next;
	static float sum_formal_salary = 0;
	static int count_formal = 0;
	static float formal_average_salary;
	while (p != NULL)
	{
		sum_formal_salary += (p->calculate_salary());
		count_formal++;
		p = p->next;
	}
	formal_average_salary = sum_formal_salary / count_formal;
	cout << "������ʽ����������Ϊ��" << sum_formal_salary << endl;
	cout << "������ʽ������Ϊ��" << count_formal << endl;
	cout << "��ʽ��ƽ������Ϊ��" << formal_average_salary << endl;
}

//ͳ����ʱ��������
informal_staff* statistical_informal_staff(informal_staff *head)
{

	if (head->next == NULL)
	{
		cerr << "���󣡣������������ݣ��뷵���������������ݻ��߶�ȡ���ݣ�" << endl;
		return head;

	}
	informal_staff *p = head->next;
	static float sum_informal_salary = 0;
	static int count_informal = 0;
	static float informal_average_salary;
	while (p != NULL)
	{
		sum_informal_salary += (p->calculate_salary());
		count_informal++;
		p = p->next;
	}
	informal_average_salary = sum_informal_salary / count_informal;
	cout << "������ʱ����������Ϊ��" << sum_informal_salary << endl;
	cout << "������ʱ������Ϊ��" << count_informal << endl;
	cout << "��ʱ��ƽ������Ϊ��" << informal_average_salary << endl;
}

//������ʽ�����ݵ��ļ�
void save_formal_staff(formal_staff *head)
{
	formal_staff *p = head->next;
	ofstream outfile("��ʽ����Ϣ.txt", ios::out);
	if (!outfile)
	{
		cerr << "�ļ���ʧ�ܣ�" << endl;
		cerr << "����ϵ����Ա����" << endl;
		system("pause");
		exit(0);
	}
	while (p != NULL)
	{
		outfile << endl;
		outfile << p->getnum() << " "<<p->getname()<<" "<<p->getsex()
			<<" "<<p->getage()<<" "<<p->getori_salary()<<" "<<p->getaddress()
			<<" "<<p->getallowance()<<" "<<p->getpension()<<" "<<p->gethousing_fund()
			<<" "<<p->gettax()<<" "<<p->getinsurance()<<" "<<p->getsalary();
		p = p->next;
	}
	outfile.close();
	p = head->next;
	ofstream outfile_dat("��ʽ����������Ϣ.dat", ios::out | ios::binary);
	if (!outfile_dat)
	{
		cerr << "�ļ���ʧ��!" << endl;
		cerr << "����ϵ����Ա����" << endl;
		system("pause");
		exit(0);
	}
	while (p != NULL)
	{
		outfile_dat.write((char*)p, sizeof(*p));
		p = p->next;

	}
	outfile_dat.close();
	cout << "������ʽ���ɹ���" << endl;
}

//������ʱ�����ݵ��ļ�
void save_informal_staff(informal_staff *head)
{
	informal_staff *p = head->next;
	ofstream outfile("��ʱ����Ϣ.txt", ios::out);
	if (!outfile)
	{
		cerr << "�ļ���ʧ�ܣ�" << endl;
		cerr << "����ϵ����Ա����" << endl;
		system("pause");
		exit(0);
	}
	while (p != NULL)
	{
	outfile << endl;
	outfile << p->getnum() << " " << p->getname() << " " << p->getsex()
		<< " " << p->getage() << " " << p->getori_salary() << " " << p->getaddress()
		<< " " << p->getbonus() << " " << p->gettax() << " " << p->getsalary();
		p = p->next;
	}
	outfile.close();
	p = head->next;
	ofstream outfile_dat("��ʱ����������Ϣ.dat", ios::out | ios::binary);
	if (!outfile_dat)
	{
		cerr << "�ļ���ʧ��!" << endl;
		cerr << "����ϵ����Ա����" << endl;
		system("pause");
		exit(0);
	}
	while (p != NULL)
	{
		outfile_dat.write((char*)p, sizeof(*p));
		p = p->next;

	}
	outfile_dat.close();
	cout << "������ʱ���ɹ���" << endl;
}

//��ȡ��ʽ�����ݵ��ڴ�
formal_staff* get_formal_staff(formal_staff *head)
{
	ifstream infile("��ʽ����������Ϣ.dat", ios::in | ios::out);
	if (!infile)
	{
		cerr << "δ�ҵ��ļ�����������ͱ�������" << endl;
		//����

	}
	infile.seekg(0, ios::beg);
	formal_staff *p, *q;
	p = q = new formal_staff;
	infile.read((char*)p, sizeof(*p));
	int i = 1;
	while (!infile.eof())
	{
		if (i == 1)
		{
			head->next = p;
		}
		else
		{
			q->next = p;

		}
		q = p;
		p = new formal_staff;
		if (p == NULL)//�����ڴ�ʧ�ܲ���  
		{
			cerr << "�쳣���󣡣����ϱ�����Ա����" << endl;
			system("pause");
			exit(0);
		}
		infile.read((char*)p, sizeof(*p));
		i++;
	}
	q->next = NULL;
	infile.close();
	return head;
}

//��ȡ��ʱ�����ݵ��ڴ�
informal_staff* get_informal_staff(informal_staff *head)
{
	ifstream infile("��ʱ����������Ϣ.dat", ios::in | ios::out);
	if (!infile)
	{
		cerr << "δ�ҵ��ļ�����������ͱ�������" << endl;
		//����

	}
	infile.seekg(0, ios::beg);
	informal_staff *p, *q;
	p = q = new informal_staff;
	infile.read((char*)p, sizeof(*p));
	int i = 1;
	while (!infile.eof())
	{
		if (i == 1)
		{
			head->next = p;
		}
		else
		{
			q->next = p;

		}
		q = p;
		p = new informal_staff;
		if (p == NULL)//�����ڴ�ʧ�ܲ���  
		{
			cerr << "�쳣���󣡣����ϱ�����Ա����" << endl;
			system("pause");
			exit(0);
		}
		infile.read((char*)p, sizeof(*p));
		i++;
	}
	q->next = NULL;
	infile.close();
	return head;
}

//�ǵ��޸����ݵ��ڴ�ĸ�ʽ ������