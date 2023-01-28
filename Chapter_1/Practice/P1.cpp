#include <windows.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>
using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;
const float Epsilon = 0.001f;
bool Equals(float lhs, float rhs)
{
	// lhs�� rhs ������ �Ÿ��� Epsilon���� ������?
	return fabs(lhs - rhs) < Epsilon ? true : false;
}
int main()
{
	cout.precision(8);

	XMVECTOR u = XMVectorSet(1.0f, 1.0f, 1.0f, 0.0f);
	XMVECTOR n = XMVector3Normalize(u);

	float LU = XMVectorGetX(XMVector3Length(n));

	// n�� u�� ����ȭ�� �����̹Ƿ� ���������δ� ���̰� �ݵ�� 1�̾�� �Ѵ�. ��ġ�����ε� �׷���?
	cout << LU << endl;
	if (LU == 1.0f)
		cout << "���� 1" << endl;
	else
		cout << "���� 1 �ƴ�" << endl;

	// 1�� ������ ������ �ŵ������ص� ������ 1�̾�� �Ѵ�. ������ �׷���?

	float powLU = powf(LU, 1.0e6f);
	cout << "LU^(10^) = " << powLU << endl;


	// EPS�� ��

	if (Equals(LU, 1.0f) == true)
		cout << "���� 1" << endl;
	else
		cout << "���� 1 �ƴ�" << endl;
}