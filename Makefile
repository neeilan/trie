run_checks:
	g++ -std=c++14 -Wall trie.cpp sanity_check.cpp -I . -o run_checks

memcheck: run_checks
	valgrind --leak-check=full --show-leak-kinds=all ./run_checks

clean:
	rm run_checks

