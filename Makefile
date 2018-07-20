run_checks:
	g++ -std=c++11 trie.cpp sanity_check.cpp -I . -o run_checks

memcheck: run_checks
	valgrind --leak-check=full --show-leak-kinds=all ./run_checks

clean:
	rm run_checks

