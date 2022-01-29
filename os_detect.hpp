enum HostOS {hUnknown, hPC, hMac};
enum HostOS g_host_os = hUnknown;

void detect_pc(void)
{
	if (g_host_os != hUnknown)
		return;

	// If the numlock is on, it's PC. Note and leave
	if (host_keyboard_led_state().num_lock)
	{
		g_host_os = hPC;
		return;
	}

	tap_code(KC_NUMLOCK); // Tap numlock
	g_host_os = host_keyboard_led_state().num_lock ? hPC : hMac;

	if (g_host_os == hPC) // It is PC, switch numlock off
		tap_code(KC_NUMLOCK);
}

void os_combo(int mod_pc, int mod_mac, int key_pc, int key_mac, bool pressed)
{
	detect_pc();

	if (pressed)
	{
		if (g_host_os == hPC)
		{
			if (mod_pc)
				register_mods(mod_pc);
			register_code(key_pc);
		}
		else
		{
			if (mod_mac)
				register_mods(mod_mac);
			register_code(key_mac);
		}
	}

	else
	{
		if (g_host_os == hPC)
		{
			if (mod_pc)
				unregister_mods(mod_pc);
			unregister_code(key_pc);
		}
		else
		{
			if (mod_mac)
				unregister_mods(mod_mac);
			unregister_code(key_mac);
		}
	}
}

