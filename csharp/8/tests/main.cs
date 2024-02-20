using System.Net;
using System.Security.AccessControl;
using Iced.Intel;
using System;
using System.Diagnostics;
using System.IO;
using System.Runtime.InteropServices;
using static ICred.Intel.AssemblerRegisters;

unsafe {
      var kernel32 = NativeLibrary.Load("kernel32.dll");
    var virtualProtectEx = (delegate* unmanaged[Cdecl, SuppressGCTransition]<nint, void*, nint, int, out int, bool>)NativeLibrary.GetExport(kernel32, "VirtualProtectEx");
    var processHandle = Process.GetCurrentProcess().Handle;

    var asm = new Assembler(64);
    asm.lea(rax, rcx + rdx);
    asm.ret();

    using var stream = new MemoryStream();
    asm.Assemble(new StreamCodeWriter(stream), 0x0);
    var code = stream.ToArray().AsMemory();
    using (var handle = code.Pin())
    {
        virtualProtectEx(processHandle, handle.Pointer, code.Length, 0x40, out _);
        var f = (delegate*<int, int, int>)handle.Pointer;
        Console.WriteLine(f(2, 3));
    }

    virtualProtectEx = null;
    NativeLibrary.Free(kernel32);
}