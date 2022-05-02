#include "lua.hpp"
#include "sol/sol.hpp"
#include <iostream>

int main(int arg_count, char** args) {
	lua_State* raw_state = luaL_newstate();
	sol::state_view state(raw_state);
	state.open_libraries(
        sol::lib::base,
        sol::lib::package,
		sol::lib::string,
		sol::lib::table,
		sol::lib::math,
		sol::lib::os,
		sol::lib::jit,
		sol::lib::ffi);

	state.script_file("inspect.lua");
	state.script_file("test.lua");
	
	return 0;
}
