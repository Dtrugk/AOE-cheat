#include <Windows.h>
#include <stdio.h>

VOID MsgBoxPayload() {
    MessageBoxA(NULL, "DLL Injection by Kiendt19", "DLL Injection!", MB_OK | MB_ICONINFORMATION);
}

DWORD WINAPI MainThread(LPVOID param) {
    // Infinite loop to check for F6 key press
    while (TRUE) {
        if (GetAsyncKeyState(VK_F1) & 0x8000) { // Check if F1 is pressed
            MessageBoxA(NULL, "F1 Pressed", "DLL Injection!", MB_OK | MB_ICONINFORMATION);
            Sleep(500); // Prevent spamming the message box
        }

        if (GetAsyncKeyState(VK_F2) & 0x8000) { // Check if F2 is pressed
            MessageBoxA(NULL, "F2 Pressed", "DLL Injection!", MB_OK | MB_ICONINFORMATION);
            Sleep(500); // Prevent spamming the message box
        }

        if (GetAsyncKeyState(VK_F3) & 0x8000) { // Check if F3 is pressed
            MessageBoxA(NULL, "F3 Pressed", "DLL Injection!", MB_OK | MB_ICONINFORMATION);
            Sleep(500); // Prevent spamming the message box
        }

        if (GetAsyncKeyState(VK_F4) & 0x8000) { // Check if F4 is pressed
            MessageBoxA(NULL, "F4 Pressed", "DLL Injection!", MB_OK | MB_ICONINFORMATION);
            Sleep(500); // Prevent spamming the message box
        }

        if (GetAsyncKeyState(VK_F5) & 0x8000) { // Check if F5 is pressed
            MessageBoxA(NULL, "F5 Pressed", "DLL Injection!", MB_OK | MB_ICONINFORMATION);
            Sleep(500); // Prevent spamming the message box
        }


        if (GetAsyncKeyState(VK_F6) & 0x8000) { // Check if F6 is pressed
            MessageBoxA(NULL, "F6 Pressed", "DLL Injection!", MB_OK | MB_ICONINFORMATION);
            Sleep(500); // Prevent spamming the message box
        }

        if (GetAsyncKeyState(VK_F7) & 0x8000) { // Check if F7 is pressed
            MessageBoxA(NULL, "F7 Pressed", "DLL Injection!", MB_OK | MB_ICONINFORMATION);
            Sleep(500); // Prevent spamming the message box
        }

        if (GetAsyncKeyState(VK_F8) & 0x8000) { // Check if F8 is pressed
            MessageBoxA(NULL, "F8 Pressed", "DLL Injection!", MB_OK | MB_ICONINFORMATION);
            Sleep(500); // Prevent spamming the message box
        }

        if (GetAsyncKeyState(VK_F9) & 0x8000) { // Check if F9 is pressed
            MessageBoxA(NULL, "F9 Pressed", "DLL Injection!", MB_OK | MB_ICONINFORMATION);
            Sleep(500); // Prevent spamming the message box
        }

        if (GetAsyncKeyState(VK_F10) & 0x8000) { // Check if F10 is pressed
            MessageBoxA(NULL, "F10 Pressed", "DLL Injection!", MB_OK | MB_ICONINFORMATION);
            Sleep(500); // Prevent spamming the message box
        }

        if (GetAsyncKeyState(VK_F11) & 0x8000) { // Check if F11 is pressed
            MessageBoxA(NULL, "F11 Pressed", "DLL Injection!", MB_OK | MB_ICONINFORMATION);
            Sleep(500); // Prevent spamming the message box
        }

        if (GetAsyncKeyState(VK_F12) & 0x8000) { // Check if F12 is pressed
            MessageBoxA(NULL, "F12 Pressed", "DLL Injection!", MB_OK | MB_ICONINFORMATION);
            Sleep(500); // Prevent spamming the message box
        }

        Sleep(100); // Delay to avoid CPU overuse
    }
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved) {
    static HANDLE hThread = NULL; // Handle to the main thread
    switch (dwReason) {
    case DLL_PROCESS_ATTACH: {
        MsgBoxPayload(); // Show initial message box when the DLL is loaded
        // Create a new thread to monitor key presses
        hThread = CreateThread(NULL, 0, MainThread, NULL, 0, NULL);
        if (!hThread) {
            MessageBoxA(NULL, "Failed to create thread!", "Error", MB_OK | MB_ICONERROR);
            return FALSE; // Indicate failure if thread creation fails
        }
        break;
    }
    case DLL_PROCESS_DETACH: {
        // Clean up and terminate the thread
        if (hThread) {
            TerminateThread(hThread, 0);
            CloseHandle(hThread);
        }
        break;
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    }
    return TRUE;
}
