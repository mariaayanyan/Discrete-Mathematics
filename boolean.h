#pragma once
bool AND(bool x, bool y) // &
{
	return x & y;
}
bool NAND(bool x, bool y) // sheffer, |
{
	return !(x & y);
}
bool OR(bool x, bool y) // V
{
	return x | y;
}
bool XOR(bool x, bool y) // +
{
	return x ^ y;
}
bool NOT(bool x) // ¬, alt + 170
{
	return !x;
}
bool NOR(bool x, bool y) // pierce, ↓, alt+25
{
	return !(x | y);
}
bool EQ(bool x, bool y) // ~
{
	return x == y;
}
bool IMPL(bool x, bool y) // →, alt + 26
{
	return x <= y;
}
