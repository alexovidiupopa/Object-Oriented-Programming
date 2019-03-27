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
	Repository *r = new Repository();
	char s[] = "abc", s2[] = "abc", s3[] = "abc", s4[] = "abc";
	Tape t(s, s2, s3, s4, 10);
	assert(r->addTapeToRepository(t));
	assert(!r->addTapeToRepository(t));
	//assert(r->removeTapeFromRepo(t));
	char tapes[101];
	tapes[0] = 0;
	r->getAllTapes(tapes);
	std::cout << tapes;
}