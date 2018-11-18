#include<stdio.h>

// 启动页式虚拟存储器
void page_vm_init(){

	// 打印页式存储器的欢迎语
	ui_print_vm_welcome(VM_TYPE_PAGE);

	// 进入命令行交互环境
	command_enter_interactive_env(VM_TYPE_PAGE);

}


void page_vm_get_command_package(){

	int *memory_pr = mmu_alloc_memory();
	int *pcb_head = mmu_alloc_process_linked_node();

	PageVMCommandPackage package = {

		vm_type : VM_TYPE_PAGE,
		memory : {

			pr: memory_pr,
			p:memory_pr
		},
		pcb : {

			head:pcb_head,
			tail:pcb_head,
			process_count:0
		}
		page_table : {

			count:0
			
		}

	};

	return package;
}
