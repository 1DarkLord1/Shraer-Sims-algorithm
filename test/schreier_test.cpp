#include "schreier_test.h"

using namespace schreier_sims;

void schreier_test::test_permutation_mult_id() noexcept {
    const std::size_t n = 5;
    permutation a(n), b(n);
    DO_CHECK((a * b == a));
}

void schreier_test::test_permutation_mult_random_perm() noexcept {
    permutation a({1, 2, 0, 4, 3}), b({3, 2, 0, 1, 4});
    DO_CHECK((a * b == permutation({4, 0, 1, 2, 3})));
}

void schreier_test::test_permutation_mult_cycle() noexcept {
    permutation a({1, 2, 3, 4, 0}), b({4, 3, 0, 2, 1});
    DO_CHECK((a * b == permutation({0, 4, 1, 3, 2})));
}

void schreier_test::test_permutation_apply_id() noexcept {
    const std::size_t n = 5;
    DO_CHECK((permutation(n) * 3 == 3));
}

void schreier_test::test_permutation_apply_random_perm() noexcept {
    DO_CHECK((permutation({3, 4, 0, 1, 5, 2}) * 2 == 0));
}

void schreier_test::test_permutation_apply_cycle() noexcept {
    DO_CHECK((permutation({1, 2, 3, 4, 0}) * 1 == 2));
}

void schreier_test::test_permutation_inv_id() noexcept {
    const std::size_t n = 5;
    permutation a(n);
    DO_CHECK((a.inv() == a));
}

void schreier_test::test_permutation_inv_random_perm() noexcept {
    DO_CHECK((permutation({4, 5, 2, 1, 3, 0}).inv() == permutation({5, 3, 2, 4, 0, 1})));
}

void schreier_test::test_permutation_inv_cycle() noexcept {
    DO_CHECK((permutation({1, 2, 3, 4, 0}).inv() == permutation({4, 0, 1, 2, 3})));
}

void schreier_test::test_schreier_tree_get_orbit_id() noexcept {
    const std::size_t n = 5;
    std::vector<permutation> perms = {permutation({0, 1, 2, 3, 4})};
    schreier_tree t(perms, n, 1);
    DO_CHECK((t.get_orbit() == std::set<uint32_t>{1}));
}

void schreier_test::test_schreier_tree_get_orbit_random_perms() noexcept {
    const std::size_t n = 5;
    std::vector<permutation> perms = {permutation({0, 2, 1, 4, 3}), permutation({1, 3, 2, 4, 0}), permutation({4, 0, 2, 3, 1})};
    schreier_tree t(perms, n, 2);
    DO_CHECK((t.get_orbit() == std::set<uint32_t>{0, 1, 2, 3, 4}));
}

void schreier_test::test_schreier_tree_get_orbit_cycles() noexcept {
    const std::size_t n = 5;
    std::vector<permutation> perms = {permutation({1, 2, 3, 4, 0}), permutation({4, 2, 3, 0, 1})};
    schreier_tree t(perms, n, 1);
    DO_CHECK((t.get_orbit() == std::set<uint32_t>{0, 1, 2, 3, 4}));
}

void schreier_test::test_schreier_tree_get_perm_id() noexcept {
    const std::size_t n = 5;
    std::vector<permutation> perms = {permutation({0, 1, 2, 3, 4})};
    schreier_tree t(perms, n, 1);
    DO_CHECK((t.get_perm(1) == permutation(n)));
}

void schreier_test::test_schreier_tree_get_perm_random_perms() noexcept {
    const std::size_t n = 5;
    std::vector<permutation> perms = {permutation({0, 2, 1, 4, 3}), permutation({1, 3, 2, 4, 0}), permutation({4, 0, 2, 3, 1})};
    schreier_tree t(perms, n, 2);
    permutation ans = perms[2] * perms[0];
    DO_CHECK((t.get_perm(0) == ans));
}

void schreier_test::test_schreier_tree_get_perm_cycles() noexcept {
    const std::size_t n = 5;
    std::vector<permutation> perms = {permutation({1, 2, 3, 4, 0}), permutation({4, 2, 3, 0, 1})};
    schreier_tree t(perms, n, 1);
    permutation ans = perms[0] * perms[0] * perms[0];
    DO_CHECK((t.get_perm(4) == ans));
}

void schreier_test::test_schreier_tree_get_perm_base() noexcept {
    const std::size_t n = 5;
    std::vector<permutation> perms = {permutation({0, 1, 2, 3, 4})};
    schreier_tree t(perms, n, 1);
    DO_CHECK((t.get_perm(1) == permutation(n)));
}

void schreier_test::run_all_tests() {
    test_permutation_mult_id();
    test_permutation_mult_random_perm();
    test_permutation_mult_cycle();
    test_permutation_apply_id();
    test_permutation_apply_random_perm();
    test_permutation_apply_cycle();
    test_permutation_inv_id();
    test_permutation_inv_random_perm();
    test_permutation_inv_cycle();

    test_schreier_tree_get_orbit_id();
    test_schreier_tree_get_orbit_random_perms();
    test_schreier_tree_get_orbit_cycles();
    test_schreier_tree_get_perm_id();
    test_schreier_tree_get_perm_random_perms();
    test_schreier_tree_get_perm_cycles();
    test_schreier_tree_get_perm_base();
}
