#ifndef MACHINE_OPERAND_HPP
#define MACHINE_OPERAND_HPP

#include "LowLevelType.hpp"
#include <cstdint>

class MachineOperand {
public:
  enum MOKind : unsigned {
    NONE,
    REGISTER,
    VIRTUAL_REGISTER,
    INT_IMMEDIATE,
    MEMORY_ADDRES,
    STACK_ACCESS,
    PARAMETER,
    LABEL
  };

  MachineOperand() {}

  void SetToVirtualRegister() { Type = VIRTUAL_REGISTER; }
  void SetToRegister() { Type = REGISTER; }
  void SetToIntImm() { Type = INT_IMMEDIATE; }
  void SetToMemAddr() { Type = MEMORY_ADDRES; }
  void SetToStackAccess() { Type = STACK_ACCESS; }
  void SetToParameter() { Type = PARAMETER; }
  void SetToLabel() { Type = LABEL; }

  int64_t GetImmediate() const { return Value; }
  int64_t GetReg() const { return Value; }
  uint64_t GetSlot() const { return Value; }
  void SetReg(uint64_t V) { SetValue(V); }
  void SetValue(uint64_t V) { Value = V; }

  void SetType(LowLevelType LLT) { this->LLT = LLT; }
  LowLevelType GetType(LowLevelType LLT) const { return LLT; }

  const char *GetLabel() { return Label; }
  void SetLabel(const char *L) { Label = L; }

  bool IsRegister() const { return Type == REGISTER; }
  bool IsVirtualReg() const { return Type == VIRTUAL_REGISTER; }
  bool IsImmediate() const { return Type == INT_IMMEDIATE; }
  bool IsMemory() const { return Type == MEMORY_ADDRES; }
  bool IsStackAccess() const { return Type == STACK_ACCESS; }
  bool IsParameter() const { return Type == PARAMETER; }
  bool IsLabel() const { return Type == LABEL; }

  static MachineOperand CreateRegister(uint64_t Reg) {
    MachineOperand MO;
    MO.SetToRegister();
    MO.SetReg(Reg);
    return MO;
  }

  static MachineOperand CreateVirtualRegister(uint64_t Reg) {
    MachineOperand MO;
    MO.SetToVirtualRegister();
    MO.SetReg(Reg);
    return MO;
  }

  static MachineOperand CreateImmediate(uint64_t Val) {
    MachineOperand MO;
    MO.SetToIntImm();
    MO.SetValue(Val);
    return MO;
  }

private:
  unsigned Type = NONE;
  uint64_t Value = ~0;
  LowLevelType LLT;
  const char *Label = nullptr;
};

#endif