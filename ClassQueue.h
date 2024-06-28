#pragma once
// Queue � ������������ ������, tail �� ��������� ������� � ������� 

using namespace std;
class Queue {

private:
	int* queue;
	int head;
	int tail;
	unsigned int N;

public:
	//������� �����������
	Queue(unsigned int _N) {
		N = _N;
		queue = new int[N];
		head = -1;
		tail = -1;
	}

	//����������
	~Queue() {
		delete[] queue;
	}

	//���������� �����������
	Queue(const Queue& q) {
		N = q.N;
		queue = new int[N];
		head = q.head;
		tail = q.tail;
		for (int i = head; i <= tail; i++) {
			queue[i] = q.queue[i];
		}
	}
	
	//����� �������
	int Length() const {
		if ((head == tail) && (head == -1))  //���� head �������� � -1
			return 0;  
		else
		return tail-head+1;
	}

	//���������� ������
	friend ostream& operator << (ostream& os, const Queue& q) {
		int len = q.Length();
		if (len != 0) {
			for (int i = q.head; i <= q.tail; i++) {
				os << q.queue[i] << " ";
			}
			return os << endl;
		}
		else
			return os << "������� ������" << endl;
	}

	//������� �����
	void shiftleft(int pos) {
		for (int i = head-1; i < pos; i++) {
			queue[i] = queue[i + 1];
		}
	}

	//������� ������
	void shiftright(int pos) {
		for (int i = tail+1; i >= pos; i--) {
			queue[i] = queue[i - 1];
		}
	}

	//������������ ���������� 0 - ��� �����, 1 - ��������
	int Add_Q(int A) {
		//��� �����
		if (Length() == N){
			cout << "������� ������\n";
			return 0;
		}                                      
		//�� �����
		else if (Length() == 0) {
			queue[0] = A;
			head = 0;
			tail = 0;
			return 1;
		}
		//���� ����� ��� �������
		else {
			short left = head;
			short right = tail;
			short sred;

			if (A >= queue[head]){
				if (head != 0){
					head--;
					queue[head] = A;
					return 1;
				}
				else{
					shiftright(0);
					queue[head] = A;
					tail++;
					return 1;
				}
			}

			if (A < queue[tail])
			{
				if (tail != N - 1) {
					tail++;
					queue[tail] = A;
					return 1;
				}
				else {
					shiftleft(N - 1);
					queue[tail] = A;
					head--;
					return 1;
				}
			}
					//����� ��� �������, ���� head �� 0 � tail �� N-1
					for (int i = head; i <= tail; i++) {
						if (A >= queue[i]) {
							sred = i; 
							break;
						}
					}

					if (tail - sred + 1 < sred - head) {
						if (tail != N - 1) {
							shiftright(sred);
							queue[sred] = A;
							tail++;
							return 1;
						}
						else{
							shiftleft(sred - 1);
							queue[sred - 1] = A;
							head--;
							return 1;
						}
					}

					else {
						if (head == 0) {
							shiftright(sred);
							queue[sred] = A;
							tail++;
							return 1;
						}
						else{
							shiftleft(sred - 1);
							queue[sred - 1] = A;
							head--;
							return 1;
						}
					}
		}
	}

	//�������� � ������ 0 - ������� ������, 1 - ������� ������
	int Pop_Q() {
		//�������� �� ������
		if (Length() == 0)     
			return 0;

		//��������� ������
		else if ((head != -1) && (Length() > 0)) {
			head = (head + 1);
			if (head > tail) {
				head = -1;
				tail = -1;
			}
			return 1;
		}
	}

	//���������� ������������
	Queue& operator= (const Queue& q) {
		if (&q != this) {
			int p = q.Length();
			if (N - 1 >= p) {
				int k = 0;
				for (int i = q.head; i <= q.tail; i++) {
					queue[k] = q.queue[i];
					k++;
				}
				head = 0;
				tail = p-1;
			}
			else {
				int k = 0;
				for (int i = 0; i < N; i++) {
					queue[k] = q.queue[i];
					k++;
				}
				head = 0;
				tail = N - 1;
			}
		
		}
		return *this;
	}
};
