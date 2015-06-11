def help_text():
    print "This is the Orchestration System v1.0"
    print "Valid Commands:"
    print "\t'help' - Displays this help message"
    print "\t'create_group' - Creates a new group"      # TODO
    print "\t'list_groups' - List all groups"           # TODO
    print "\t'boot_group' - Boots a group"              # TODO
    print "\t'shutdown_group' - Shuts down a group"     # TODO
    print "\t'view_group' - Views a group"              # TODO
    print "\t'create_host' - Creates a new host"        # TODO
    print "\t'list_hosts' - List all hosts"             # TODO
    print "\t'boot_host' - Boots a host"                # TODO
    print "\t'activate_host' - Activates a host"        # TODO
    print "\t'deactivate_host' - Deactivates a host"    # TODO
    print "\t'shutdown_host' - Shuts down a host"       # TODO
    print "\t'exit' or 'quit' - Quits the Orchestration System"



if __name__ == "__main__":
    print "Orchestration System v1.0"
    print "-------------------------"

    print

    while True:
        command = raw_input("Orch> ")

        command = command.strip().lower()

        if command == "quit" or command == "exit":
            print "Thanks for using the Orchestration System"
            break
        elif command == "help":
            help_text()

        # TODO: Add more commands here to allow for creating and managing groups and hosts

        else:
            print "Orch! {}: Not Recognized, try 'help' for a list of valid commands".format(command)





