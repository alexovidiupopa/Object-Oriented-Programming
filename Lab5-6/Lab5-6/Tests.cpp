#include "Tests.h"
#include <assert.h>
#include <iostream>
void testCreate()
{
	char s[]="abc", s2[] = "abc", s3[] = "abc", s4[] = "abc";
	Tape t(s,s2,s3,s4,10);
	assert(t.getAccessCount() == 10);
	t.setAccessCount(20);
	assert(t.getAccessCount() == 20);
}

void testRepo()
{
	Repository r{};
	char s[] = "abc", s2[] = "abc", s3[] = "abc", s4[] = "abc";
	Tape t(s, s2, s3, s4, 10);
	assert(r.addTapeToRepository(t));
	assert(!r.addTapeToRepository(t));
	assert(r.removeTapeFromRepo(t.getTitle()));
	assert(r.addTapeToRepository(t));
	strcpy(s2, "abd");
	Tape t2(s, s2, s3, s4, 10);
	assert(r.updateTapeInRepo(t2));
	DynamicVector dv = r.getAllTapes();
	Tape* elems = dv.getAllElements();
	assert(strcmp(elems[0].getFilmedAt(), "abd") == 0);
}

void testController()
{
	Repository r{};
	Controller c{ r };
	char s[] = "abc", s2[] = "here there", s3[] = "creation date", s4[] = "preview";
	assert(c.addTape(s,s2,s3,s4,10));
	char x[10] = "abdcefgh", x2[25] = "here there", x3[] = "creation date", x4[] = "preview";
	assert(c.addTape(x, x2, x3, x4, 11));
	strcat(x, "x");
	assert(!c.removeTape(x));
	assert(c.removeTape(s));
	strcat(x2, " everywhere");
	strcpy(x, "abdcefgh");
	assert(c.updateTape(x, x2, x3, x4, 12));
	strcpy(x, "abdcefg2h");
	assert(!c.updateTape(x, x2, x3, x4, 12));
}
void runTests()
{
	testCreate();
	testRepo();
	testController();
}