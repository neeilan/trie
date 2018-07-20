run_checks:
	g++ -std=c++11 trie.cpp sanity_check.cpp -I . -o run_checks

clean:
	rm run_checks

