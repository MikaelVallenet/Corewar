// The module 'vscode' contains the VS Code extensibility API
// Import the module and reference it with the alias vscode in your code below
const vscode = require('vscode');

// this method is called when your extension is activated
// your extension is activated the very first time the command is executed

/**
 * @param {vscode.ExtensionContext} context
 */
function activate(context) {

	console.log('Corewar-code activated.\nBack in the good old days...');

	let disposable = vscode.commands.registerCommand('corewar-code.showTime', function () {
	
		var current = new Date();
		vscode.window.showInformationMessage('Il est actuellement ' + current);
	});

	context.subscriptions.push(disposable);
	context.subscriptions.push(
		vscode.languages.registerHoverProvider('redcode', {
			provideHover(document, position, token) {

				const range = document.getWordRangeAtPosition(position);
				const word = document.getText(range);
			
				if (word == "name") {
					return new vscode.Hover({
						language: "redcode",
						value: "Reserved to the champion name. It must be under 124 bytes."
					});
				}
				if (word == "comment") {
					return new vscode.Hover({
						language: "redcode",
						value: "Reserved to the champion comment. It must be under 2048 bytes."
					});
				}
				if (word == "live") {
					return new vscode.Hover({
						language: "redcode",
						value: "live %\[4 bytes\]\nIndicates that the player is alive."
					});
				}
				if (word == "ld") {
					return new vscode.Hover({
						language: "redcode",
						value: "ld arg1,arg2\nIt loads the value of the first parameter into the second parameter, which must be a register (not the PC).\nThis operation modifies the carry.\nld 34,r3 loads the REG_SIZE bytes starting at the address PC + 34 % IDX_MOD into r3"
					});
				}
				if (word == "st") {
					return new vscode.Hover({
						language: "redcode",
						value: "st arg1,arg2\nIt stores the first parameter’s value (which is a register) into the second (whether a register or a number).\nst r4,34 stores the content of r4 at the address PC + 34 % IDX_MOD. st r3,r8 copies the content of r3 into r8."
					});
				}
				if (word == "add") {
					return new vscode.Hover({
						language: "redcode",
						value: "add r1,r2,r3\nIt adds the content of the first two and puts the sum into the third one (which must be a register).\nThis operation modifies the carry.\nadd r2,r3,r5 adds the content of r2 and r3 and puts the result into r5."
					});
				}
				if (word == "sub") {
					return new vscode.Hover({
						language: "redcode",
						value: "sub r1,r2,r3\nIt subs the content of the first two and puts the subs into the third one (which must be a register).\nThis operation modifies the carry.\nsub r2,r3,r5 subs the content of r2 and r3 and puts the result into r5."
					});
				}
				if (word == "and") {
					return new vscode.Hover({
						language: "redcode",
						value: "and arg1,arg2,arg3\nIt performs a binary AND between the first two parameters and stores the result into the third one (which must be a register).\nThis operation modifies the carry.\nand r2,%0,r3 puts r2 & 0 into r3."
					});
				}
				if (word == "or") {
					return new vscode.Hover({
						language: "redcode",
						value: "or arg1,arg2,arg3\nIt performs a binary OR between the first two parameters and stores the result into the third one (which must be a register).\nThis operation modifies the carry.\nor r2,%0,r3 puts r2 | 0 into r3."
					});
				}
				if (word == "xor") {
					return new vscode.Hover({
						language: "redcode",
						value: "xor arg1,arg2,arg3\nIt performs a binary XOR between the first two parameters and stores the result into the third one (which must be a register).\nThis operation modifies the carry.\nxor r2,%0,r3 puts r2 ^ 0 into r3."
					});
				}
				if (word == "zjmp") {
					return new vscode.Hover({
						language: "redcode",
						value: "zjmp index\nIt jumps to this index if the carry is worth 1. Otherwise, it does nothing but consumes the same time.\nzjmp %23 puts, if carry equals 1, PC + 23 % IDX_MOD into the PC"
					});
				}
				if (word == "ldi") {
					return new vscode.Hover({
						language: "redcode",
						value: "ldi index1,index2,r3\nThis operation modifies the carry.\nldi 3,%4,r1 reads IND_SIZ bytes from the address PC + 3 % IDX_MOD, adds 4 to this value.The sum is named S.REG_SIZE bytes are read from the address PC + S % IDX_MOD and copied into r1"
					});
				}
				if (word == "sti") {
					return new vscode.Hover({
						language: "redcode",
						value: "sti r1,r2|index2,r3|index3\nsti r2,%4,%5 copies the content of r2 into the address PC + (4+5)% IDX_MOD"
					});
				}
				if (word == "fork") {
					return new vscode.Hover({
						language: "redcode",
						value: "fork index\nIt creates a new program that inherits different states from the parent. This program is executed at the address 'PC + first parameter % IDX_MOD.'"
					});
				}
				if (word == "lld") {
					return new vscode.Hover({
						language: "redcode",
						value: "lld arg1,arg2\nIt loads the value of the first parameter into the second parameter, which must be a register (not the PC).\nThis operation modifies the carry.\nld 34,r3 loads the REG_SIZE bytes starting at the address PC + 34 into r3"
					});
				}
				if (word == "lldi") {
					return new vscode.Hover({
						language: "redcode",
						value: "lldi index1,index2,r3\nThe first two must be indexes, the third one must be a register.\nThis operation modifies the carry.\nldi 3,%4,r1 reads IND_SIZ bytes from the address PC + 3 % IDX_MOD, adds 4 to this value.The sum is named S.REG_SIZE bytes are read from the address PC + S and copied into r1"
					});
				}
				if (word == "lfork") {
					return new vscode.Hover({
						language: "redcode",
						value: "lfork index\nIt creates a new program that inherits different states from the parent. This program is executed at the address 'PC + first parameter.'"
					});
				}
				if (word == "aff") {
					return new vscode.Hover({
						language: "redcode",
						value: "aff r1\nIt displays on the standard output the character whose ASCII code is the content of the register (in base 10). A 256 modulo is applied to this ASCII code.\naff r3 displays ’*’ if r3 contains 42"
					});
				}
			}
		
		}));
}

// this method is called when your extension is deactivated
function deactivate() {
	console.log('Corewar-code deactivated.\nJust as before...');
}

module.exports = {
	activate,
	deactivate
}
