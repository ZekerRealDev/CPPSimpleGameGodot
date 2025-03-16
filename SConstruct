#!/usr/bin/env python

import os

EnsureSConsVersion(4, 0)

try:
    Import("env")
except Exception:
    env = Environment(tools=["default"], PLATFORM="")

# Usando Clang
env["CC"] = "clang"
env["CXX"] = "clang++"

# Adicionando flags de otimização
env.Append(CXXFLAGS=["-O3", "-march=native", "-funroll-loops", "-flto", "-fomit-frame-pointer", "-ftree-vectorize"])

env.PrependENVPath("PATH", os.getenv("PATH"))

# Definindo o perfil e outras configurações
customs = ["custom.py"]
try:
    customs += Import("customs")
except Exception:
    pass
profile = ARGUMENTS.get("profile", "")
if profile:
    if os.path.isfile(profile):
        customs.append(profile)
    elif os.path.isfile(profile + ".py"):
        customs.append(profile + ".py")
opts = Variables(customs, ARGUMENTS)
cpp_tool = Tool("godotcpp", toolpath=["tools"])
cpp_tool.options(opts, env)
opts.Update(env)

Help(opts.GenerateHelpText(env))

# Detectando variáveis desconhecidas
unknown = opts.UnknownVariables()
if unknown:
    print("WARNING: Unknown SCons variables were passed and will be ignored:")
    for item in unknown.items():
        print("    " + item[0] + "=" + item[1])

# Definindo o cache para SCons
scons_cache_path = os.environ.get("SCONS_CACHE")
if scons_cache_path is not None:
    CacheDir(scons_cache_path)
    Decider("MD5")

cpp_tool.generate(env)
library = env.GodotCPP()

Return("env")
